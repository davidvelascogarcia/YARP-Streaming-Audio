//****************************************************
//****************************************************
//
//              YARP: Streaming Audio
//
//              Tipo: Receptor
//
//              Autor: David Velasco García
//		       @davidvelascogarcia
//
//****************************************************
//****************************************************

// Librerias

#include <stdio.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/AudioGrabberInterfaces.h>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <iostream>

// Espacio de nombres

using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::dev;
using namespace std;

// Funcion main

int main(int argc, char *argv[]) {

    cout<<" Iniciando red YARP"<<endl;
    Network yarp;
    cout<<" Abriendo puerto de recepción con nombre /reciever"<<endl;
    BufferedPort<Sound> p;
    p.open("/receiver");
    cout<<" Conectando puerto emisor y recptor"<<endl;
    Network::connect("/sender", "/receiver");
    cout<<" Configurando receptor de audio"<<endl;
    Property conf;
    conf.put("device","portaudio");
    conf.put("samples", "4096");
    conf.put("write", "1");
    PolyDriver poly(conf);
    IAudioRender *put;
    poly.view(put);
    if (put==NULL) {
    cout<<" Lo siento, no se ha podido abrir el dispositivo"<<endl;
        return 1;
    }

    cout<<" Recibiendo audio..."<<endl;
    Sound *s;
    while (true)
      {
    s = p.read(false);
    if (s!=NULL)
        put->renderSound(*s);
      }
    return 0;
}