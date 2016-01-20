#ifndef QMIDIOUT_H
#define QMIDIOUT_H

#include <QObject>
#include "RtMidi.h"
#include "qmidimessage.h"

class QMidiOut : public QObject
{
    Q_OBJECT
public:
    explicit QMidiOut(QObject *parent = 0);
    void noteOn(unsigned int note, unsigned int value);
    QStringList getPorts();
    void sendNoteOn(unsigned int channel, unsigned int pitch, unsigned int velocity);
    void sendNoteOff(unsigned int channel, unsigned int pitch, unsigned int velocity);
    void sendRawMessage(std::vector<unsigned char> &message);
    void sendMessage(QMidiMessage *message);
    void openPort(unsigned int index);
private:
    RtMidiOut *_midiOut;


signals:

public slots:
};

#endif // QMIDIOUT_H