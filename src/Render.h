#ifndef RENDER_H
#define RENDER_H

#include <QThread>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <CommandQueue.h>
#include <Interface.h>

#define INCPOS      100
#define INCZ        0.5
#define ZOOMLIMIT   10.0
#define MARGEM      0.05

class Render : public QThread
{
	Q_OBJECT

signals:
        void renderizado(const QImage &screen);

        
public slots:
    void updateScreen(int w, int y);
    void recebeArquivo(const QString &);

                
public:
        Render(int w, int y, CommandQueue *c);

    void run(void);

private:
        void atualizaScreen(void);
        void incX();
        void decX();
        void incY();
        void decY();
        void incZoom();
        void decZoom();
        QPoint transforma(const QPoint &);
        QPoint destransforma(const QPoint &);
        void renderiza(void);
        void seleciona(void);
        QPoint buscaPontoFino(QPoint ent);
        QPair<QPoint, QPoint> buscaPontoGrosso(QPoint ent);
        QPair<QPair<QPoint, QPoint> , QPair<QPoint, QPoint> > buscaArestaFina(QPoint ent);
        QPair<QPoint, QPoint> buscaArestaGrossa();

	    
        QImage* screen;
        QImage* buffer;
        QImage* backBuffer;
        QImage* frontBuffer;
        double zoom;
        CommandQueue *cmdq;
        QPoint *ponto;
        QPoint *sel;
        int screenW;
        int screenH;
        bool mostraPonto;
        bool mostraAresta;
        bool mostraFace;
        Interface interface;
        QMap<QPoint , QPoint> map;
        QPen arestaScreen;
        QPen selecionadoScreen;
        //QPen faceSelecionadaScreen;
        QRgb corArestaFina;
        QRgb corArestaGrossa;
        QRgb corVerticeFino;
        QRgb corVerticeGrosso;
        QRgb corFace;
        QRgb corFaceExt;

        QPen faceExternaBack;
        QPen arestaGrossaBack;
        QPen verticeGrossoBack;
        QPen arestafinaBack;
        QPen verticefinoBack;



        
};

#endif