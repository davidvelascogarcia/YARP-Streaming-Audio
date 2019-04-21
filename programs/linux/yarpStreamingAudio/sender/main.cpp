//****************************************************
//****************************************************
//
//              YARP: Streaming Audio
//
//              Tipo: Sender
//
//              Autor: David Velasco García
//		       @davidvelascogarcia
//
//****************************************************
//****************************************************

// Libraries

#include <stdio.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/AudioGrabberInterfaces.h>
#include <yarp/os/Property.h>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/Time.h>
#include <iostream>

// Espacio de nombres

using namespace std;
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::dev;

// Tiempo de grabacion

const int rec_seconds = 1;

// Funcion main

int main(int argc, char *argv[]) {

    cout<<"Iniciando red yarp..."<<endl;
    Network yarp;
    cout<<"Abriendo puerto emisor con nombre /yarpStreamingAudio/audio:o"<<endl;
    Port p;
    p.open("/yarpStreamingAudio/audio:o");
    cout<<"Iniciando dispositivo emisor..."<<endl;
    Property conf;
    conf.put("device","portaudio");
    conf.put("read", "");
    conf.put("samples", 44100*rec_seconds);
    PolyDriver poly(conf);
    IAudioGrabberSound *get;
    poly.view(get);
    if (get==NULL) {
    cout<<"Lo siento, no se ha podido abrir el dispositivo"<<endl;
        return 1;
    }
    cout<<"Enviando audio..."<<endl;
    Sound s;
    get->startRecording(); 
    while (true)
    {
        double t1=yarp::os::Time::now();
        get->getSound(s);
        double t2=yarp::os::Time::now();
        printf("acquired %f seconds\n", t2-t1);
        p.write(s);
    }
    get->stopRecording();  //stops recording.
    return 0;
}
