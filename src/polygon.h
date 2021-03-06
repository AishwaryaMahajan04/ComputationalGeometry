/*
  polygon.h
  2013-03-10 pg22577@alunos.uminho.pt

  Purpose:
  - Polygon manipulation library.

  Features:
  - Polygon vertices are represented by 2D points 
    with integer coordinates.
  - Polygon vertices can have arbitrary meta information
    associated with them.

  Reference:
  - Computational Geometry in C (2nd ed)
    Joseph O'Rourke
*/
#ifndef POLYGON_H
#define POLYGON_H

#include <assert.h>
#include <stdlib.h>
#include "point.h"

typedef struct Polygon * Polygon;
typedef struct PolygonVertex * PolygonVertex;
typedef void * PolygonVertexMeta;

/* Returns a new empty polygon, or NULL on failure. */
Polygon NewPolygon (void);

/* Destroys a previously created polygon and all its related data. */
void FreePolygon (Polygon *);

/* Returns the total number of vertices present in this polygon. */
size_t PolygonSize (const Polygon);

/* Returns an arbitrary vertex, or NULL if none are present. */
PolygonVertex SomeVertex (const Polygon);

/* The same as AppendVertexWithMeta (_, _, n), where *n == NULL. */
PolygonVertex AppendVertex (Polygon, const struct Point *);

/* Sets the given point as the next counterclockwise vertex of
   this polygon. Returns the said new vertex, or NULL on failure. */
PolygonVertex AppendVertexWithMeta (Polygon, const struct Point *, PolygonVertexMeta *);

/* Returns the vertex coordinates. */
void VertexPoint (const PolygonVertex, struct Point *);

/* Returns the vertex's meta. */
void VertexMeta (const PolygonVertex, PolygonVertexMeta *);

/* Updates the vertex's meta. */
void UpdateVertexMeta (PolygonVertex, PolygonVertexMeta *);

/* Takes the given vertex out of the polygon and deletes it. 
   Caution: the given vertex must belong to the given polygon. */
void RemoveVertex (Polygon, PolygonVertex *);

/* Returns the adjacent vertices, counterclockwise: a-v-b. */
void AdjacentVertices (const PolygonVertex v, PolygonVertex * a, PolygonVertex * b);

/* Returns 1 if the vertex is convex. */
int IsConvex (const PolygonVertex);

/* Returns 1 if the line segment is a diagonal. */
int IsDiagonal (const Polygon, const PolygonVertex, const PolygonVertex);

#endif /* POLYGON_H */
