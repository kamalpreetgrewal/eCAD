/**
 * arrow.h
 *
 * Copyright (C) 2014 GreatDevelopers
 *
 * eCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * eCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ARROW_H
#define ARROW_H

#include <QPainter>

#include "qmath.h"

class Arrow
{
public:
    Arrow(int, QPointF, QPointF);
    Arrow(int, QPointF, QPointF, QPointF);
    qreal getAngle(const qreal, const qreal);
    QPainterPath getArrowPath();
    void calculate(int);

    bool horizontal, vertical, radial;
    QPointF startP, midP, endP;
    QPointF middle;
    QLineF line;
    QPolygonF headPolygon, tailPolygon;
    qreal lineAngle, textHeight, textWidth, padding;
    QString value;
    QFont font;
};

#endif // ARROW_H
