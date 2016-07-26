/*
Copyright(c) 2016 Panos Karabelas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

//==================================
#include <QWidget>
#include <QGridLayout>
#include "DirectusComboSliderText.h"
#include <QPushButton>
#include "Core/GameObject.h"
#include <QDoubleValidator>
#include "Components/MeshCollider.h"
#include <QCheckBox>
#include "DirectusCore.h"
#include <QLabel>
#include "Math/Vector4.h"
//==================================

class DirectusInspector;

class DirectusMeshCollider : public QWidget
{
    Q_OBJECT
public:
    explicit DirectusMeshCollider(QWidget *parent = 0);
    void Initialize(DirectusCore* directusCore, DirectusInspector* inspector);
    void Reflect(GameObject* gameobject);

private:
    //= TITLE ============================
    QLabel* m_title;
    //====================================

    //= CONVEX ===========================
    QLabel* m_convexLabel;
    QCheckBox* m_convex;
    //====================================

    //= MESH =============================
    QLabel* m_meshLabel;
    QLineEdit* m_mesh;
    //====================================

    //= LINE =============================
    QWidget* m_line;
    //====================================

    //= MISC =============================
    QGridLayout* m_gridLayout;
    QValidator* m_validator;
    MeshCollider* m_inspectedMeshCollider;
    DirectusCore* m_directusCore;
    //====================================

    void SetConvex(bool convex);
    void SetMesh(Mesh* mesh);

public slots:
    void MapConvex();
    void MapMesh();
};
