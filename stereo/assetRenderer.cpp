#include "main.h"

#include <boost/filesystem.hpp>

void AssetRenderer::init(ml::D3D11GraphicsDevice &g)
{
    m_shaders.init(g);
    m_shaders.registerShader("../../shaders/modelRendererColor.shader", "basicColor");
    m_shaders.registerShader("../../shaders/modelRendererTexture.shader", "basicTexture");
    m_constants.init(g);

    m_sphere.load(g, ml::shapes::sphere(1.0f, vec3f::origin));
    m_cylinder.load(g, ml::shapes::cylinder(0.01f, 1.0f, 2, 15, ml::vec4f(1.0f, 1.0f, 1.0f, 1.0f)));
    m_box.load(g, ml::shapes::box(1.0f));
}

void AssetRenderer::renderMesh(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const ml::D3D11TriMesh &mesh, const vec3f &color)
{
    renderMesh(g, cameraPerspective, mat4f::identity(), mesh, color);
}

void AssetRenderer::renderMesh(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const mat4f &meshToWorld, const ml::D3D11TriMesh &mesh, const vec3f &color)
{
    m_shaders.bindShaders("basicColor");

    AssetRendererConstantBuffer constants;

    constants.worldViewProj = cameraPerspective * meshToWorld;
    constants.modelColor = ml::vec4f(color, 1.0f);
    m_constants.updateAndBind(g, constants, 0);
    mesh.render(g);
}

void AssetRenderer::renderSphere(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const vec3f &center, float radius, const vec3f &color)
{
    renderMesh(g, cameraPerspective, mat4f::translation(center) * mat4f::scale(-radius), m_sphere, color);
}

void AssetRenderer::renderCylinder(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const vec3f &p0, const vec3f &p1, const vec3f &color)
{
    renderMesh(g, cameraPerspective, mat4f::translation(p0) * mat4f::face(vec3f::eZ, p1 - p0) * mat4f::scale(1.0f, 1.0f, vec3f::dist(p0, p1)), m_cylinder, color);
}

void AssetRenderer::renderBox(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const vec3f &center, float radius, const vec3f &color)
{
    renderMesh(g, cameraPerspective, mat4f::translation(center) * mat4f::scale(radius), m_box, color);
}

void AssetRenderer::renderPolygon(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const Polygonf &poly, const vec3f &color, float height)
{
    for (const auto &segment : poly.segments())
    {
        renderCylinder(g, cameraPerspective, vec3f(segment.p0(), height), vec3f(segment.p1(), height), color);
        renderSphere(g, cameraPerspective, vec3f(segment.p0(), height), 0.02f, color);
    }
}
