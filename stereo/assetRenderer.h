
struct AssetRendererConstantBuffer
{
    mat4f worldViewProj;
    vec4f modelColor;
};

class AssetRenderer
{
public:
    void init(ml::D3D11GraphicsDevice &g);
    
    void renderMesh(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const ml::D3D11TriMesh &mesh, const vec3f &color = vec3f(1.0f, 1.0f, 1.0f));
    void renderMesh(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const mat4f &meshToWorld, const ml::D3D11TriMesh &mesh, const vec3f &color = vec3f(1.0f, 1.0f, 1.0f));

    void renderCylinder(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const vec3f &p0, const vec3f &p1, const vec3f &color);
    void renderSphere(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const vec3f &center, float radius, const vec3f &color);
    void renderBox(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const vec3f &center, float radius, const vec3f &color);

    void renderPolygon(ml::GraphicsDevice &g, const mat4f &cameraPerspective, const Polygonf &poly, const vec3f &color, float height);

    const ml::D3D11TriMesh& sphereMesh() const
    {
        return m_sphere;
    }

    const ml::D3D11TriMesh& boxMesh() const
    {
        return m_box;
    }

private:
    D3D11ShaderManager m_shaders;
    ml::D3D11ConstantBuffer<AssetRendererConstantBuffer> m_constants;

    D3D11TriMesh m_cylinder;
    D3D11TriMesh m_sphere;
    D3D11TriMesh m_box;
};
