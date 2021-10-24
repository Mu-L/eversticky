/*
 * This file is part of the EverSticky project (https://github.com/itsmejoeeey/eversticky).
 * Copyright (c) 2021 Joey Miller.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "note_scroll_area.h"

#include <QCommonStyle>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QWheelEvent>

#include "ui/note_header.h"
#include "webview/note_webview.h"


NoteScrollArea::NoteScrollArea(QWidget *context) : QScrollArea(context)
{
    setObjectName("NoteScrollArea");

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setWidgetResizable(true);

    QWidget *scrollContainer = new QWidget();
    dockLayout = new QVBoxLayout();
    dockLayout->setSpacing(0);
    dockLayout->setContentsMargins(QMargins());
    dockLayout->setAlignment(Qt::AlignTop);

    scrollContainer->setLayout(dockLayout);
    setWidget(scrollContainer);
}

void NoteScrollArea::addWidget(QWidget *widget)
{
    dockLayout->addWidget(widget);
}

void NoteScrollArea::scrollNote(int dx, int dy)
{
    const int x = horizontalScrollBar()->value() - dx;
    horizontalScrollBar()->setValue( x );

    const int y = verticalScrollBar()->value() - dy;
    verticalScrollBar()->setValue( y );
}
