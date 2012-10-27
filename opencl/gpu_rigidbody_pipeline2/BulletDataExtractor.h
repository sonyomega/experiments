#ifndef BULLET_DATA_EXTRACTOR_H
#define BULLET_DATA_EXTRACTOR_H


#include "BulletSerialize/BulletFileLoader/autogenerated/bullet.h"
#include "LinearMath/btAlignedObjectArray.h"
#include "LinearMath/btVector3.h"

class GLInstancingRenderer;
struct CLPhysicsDemo;

void createScene(GLInstancingRenderer& renderer,CLPhysicsDemo& physicsSim, bool useConvexHeightfield, const char* fileName);

namespace bParse
{
	class btBulletFile;
};

class btBulletDataExtractor
{
	GLInstancingRenderer&	m_renderer;
	CLPhysicsDemo&			m_physicsSim;
	

	public:

	btAlignedObjectArray<struct InstanceGroup*> m_instanceGroups;
	btAlignedObjectArray<struct GraphicsShape*> m_graphicsShapes;

	btBulletDataExtractor(GLInstancingRenderer&	renderer, CLPhysicsDemo&	physicsSim);
	
	virtual ~btBulletDataExtractor();
	
	virtual void convertAllObjects(bParse::btBulletFile* bulletFile);
	
	//return -1 for invalid
	virtual int convertCollisionShape(  Bullet::btCollisionShapeData* shapeData  );

	virtual int createPlaneShape( const Bullet::btVector3FloatData& planeNormal, float planeConstant, const Bullet::btVector3FloatData& localScaling);
	
	virtual int createBoxShape( const Bullet::btVector3FloatData& halfDimensions, const Bullet::btVector3FloatData& localScaling, float collisionMargin);

	virtual int createSphereShape( float radius, const Bullet::btVector3FloatData& localScaling, float collisionMargin);

	static GraphicsShape* createGraphicsShapeFromConvexHull(const btVector3* tmpPoints, int numPoints);
	static GraphicsShape* createGraphicsShapeFromWavefrontObj(class objLoader* obj);

};


	
#endif //BULLET_DATA_EXTRACTOR_H