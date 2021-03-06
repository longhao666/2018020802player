/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "videowidget.h"

#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>

#define LHDEBUG 0

VideoWidget::VideoWidget(QWidget *parent)
    : QVideoWidget(parent)
{
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::black);
    setPalette(p);

    setAttribute(Qt::WA_OpaquePaintEvent);
}

void VideoWidget::keyPressEvent(QKeyEvent *event)
{
    //Qt::Key_Escape  0x01000000
    //isFullScreen() 是否全屏,默认为false
    //== > & > &&
#if LHDEBUG
//    qDebug() << "1isFullScreen() =" << isFullScreen();
#endif
    if (event->key() == Qt::Key_Escape && isFullScreen()) {

#if LHDEBUG
    qDebug() << "2isFullScreen() =" << isFullScreen();
#endif
        //设置成非全屏
        setFullScreen(false);
        event->accept();
    } else if (event->key() == Qt::Key_Enter && event->modifiers() & Qt::Key_Alt) {
#if LHDEBUG
    qDebug() << "3isFullScreen() =" << isFullScreen();
#endif
        setFullScreen(!isFullScreen());
        event->accept();
    } else {
#if LHDEBUG
    qDebug() << "4isFullScreen() =" << isFullScreen();
#endif
        QVideoWidget::keyPressEvent(event);
    }
#if LHDEBUG
    qDebug() << "5isFullScreen() =" << isFullScreen();
#endif
}

/**
 * @brief VideoWidget::mouseDoubleClickEvent
 * @param event
 * 双击视频播放框全屏(播放视频的全屏,不是软件全屏)
 */
void VideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    setFullScreen(!isFullScreen());
    event->accept();
}

/**
 * @brief VideoWidget::mousePressEvent
 * @param event
 * 点击视频播放框可以触发这个事件
 */
void VideoWidget::mousePressEvent(QMouseEvent *event)
{
#if 1
    qDebug() << event->x() << event->y();
    qDebug() << "event->x() << event->y()";
    qDebug() << event;
    qDebug() << &event << &(*event);
#endif
    QVideoWidget::mousePressEvent(event);
}

