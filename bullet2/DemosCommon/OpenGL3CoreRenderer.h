#ifndef OPENGL3_CORE_RENDERER_H
#define OPENGL3_CORE_RENDERER_H

class btCollisionObject;
class GLInstancingRenderer;

class OpenGL3CoreRenderer
{

	GLInstancingRenderer* m_instanceRenderer;
public:
	OpenGL3CoreRenderer();
	virtual ~OpenGL3CoreRenderer();
	void init();
	void reshape(int w, int h); 
	void keyboardCallback(unsigned char key);
	void renderPhysicsWorld(int numObjects, btCollisionObject** colObjArray);

};

#endif //OPENGL3_CORE_RENDERER_H

