class PhysFeModelDesc_t
{
	CUtlVector< uint32 > m_CtrlHash;
	CUtlVector< CUtlString > m_CtrlName;
	uint32 m_nStaticNodeFlags;
	uint32 m_nDynamicNodeFlags;
	float32 m_flLocalForce;
	float32 m_flLocalRotation;
	uint16 m_nNodeCount;
	uint16 m_nStaticNodes;
	uint16 m_nRotLockStaticNodes;
	uint16 m_nFirstPositionDrivenNode;
	uint16 m_nSimdTriCount1;
	uint16 m_nSimdTriCount2;
	uint16 m_nSimdQuadCount1;
	uint16 m_nSimdQuadCount2;
	uint16 m_nQuadCount1;
	uint16 m_nQuadCount2;
	uint16 m_nTreeDepth;
	uint16 m_nNodeBaseJiggleboneDependsCount;
	uint16 m_nRopeCount;
	CUtlVector< uint16 > m_Ropes;
	CUtlVector< FeNodeBase_t > m_NodeBases;
	CUtlVector< FeSimdNodeBase_t > m_SimdNodeBases;
	CUtlVector< FeQuad_t > m_Quads;
	CUtlVector< FeSimdQuad_t > m_SimdQuads;
	CUtlVector< FeSimdTri_t > m_SimdTris;
	CUtlVector< FeSimdRodConstraint_t > m_SimdRods;
	CUtlVector< FeSimdRodConstraintAnim_t > m_SimdRodsAnim;
	CUtlVector< CTransform > m_InitPose;
	CUtlVector< FeRodConstraint_t > m_Rods;
	CUtlVector< FeTwistConstraint_t > m_Twists;
	CUtlVector< FeHingeLimit_t > m_HingeLimits;
	CUtlVector< FeAntiTunnelProbe_t > m_AntiTunnelProbes;
	CUtlVector< uint16 > m_AntiTunnelTargetNodes;
	CUtlVector< FeAxialEdgeBend_t > m_AxialEdges;
	CUtlVector< float32 > m_NodeInvMasses;
	CUtlVector< FeCtrlOffset_t > m_CtrlOffsets;
	CUtlVector< FeCtrlOsOffset_t > m_CtrlOsOffsets;
	CUtlVector< FeFollowNode_t > m_FollowNodes;
	CUtlVector< FeCollisionPlane_t > m_CollisionPlanes;
	CUtlVector< FeNodeIntegrator_t > m_NodeIntegrator;
	CUtlVector< FeSpringIntegrator_t > m_SpringIntegrator;
	CUtlVector< FeSimdSpringIntegrator_t > m_SimdSpringIntegrator;
	CUtlVector< FeWorldCollisionParams_t > m_WorldCollisionParams;
	CUtlVector< float32 > m_LegacyStretchForce;
	CUtlVector< float32 > m_NodeCollisionRadii;
	CUtlVector< float32 > m_DynNodeFriction;
	CUtlVector< float32 > m_LocalRotation;
	CUtlVector< float32 > m_LocalForce;
	CUtlVector< FeTaperedCapsuleStretch_t > m_TaperedCapsuleStretches;
	CUtlVector< FeTaperedCapsuleRigid_t > m_TaperedCapsuleRigids;
	CUtlVector< FeSphereRigid_t > m_SphereRigids;
	CUtlVector< uint16 > m_WorldCollisionNodes;
	CUtlVector< uint16 > m_TreeParents;
	CUtlVector< uint16 > m_TreeCollisionMasks;
	CUtlVector< FeTreeChildren_t > m_TreeChildren;
	CUtlVector< uint16 > m_FreeNodes;
	CUtlVector< FeFitMatrix_t > m_FitMatrices;
	CUtlVector< FeFitWeight_t > m_FitWeights;
	CUtlVector< FeNodeReverseOffset_t > m_ReverseOffsets;
	CUtlVector< FeAnimStrayRadius_t > m_AnimStrayRadii;
	CUtlVector< FeSimdAnimStrayRadius_t > m_SimdAnimStrayRadii;
	CUtlVector< FeKelagerBend2_t > m_KelagerBends;
	CUtlVector< FeCtrlSoftOffset_t > m_CtrlSoftOffsets;
	CUtlVector< CFeIndexedJiggleBone > m_JiggleBones;
	CUtlVector< uint16 > m_SourceElems;
	CUtlVector< uint32 > m_GoalDampedSpringIntegrators;
	CUtlVector< FeTri_t > m_Tris;
	uint16 m_nTriCount1;
	uint16 m_nTriCount2;
	uint8 m_nReservedUint8;
	uint8 m_nExtraPressureIterations;
	uint8 m_nExtraGoalIterations;
	uint8 m_nExtraIterations;
	CUtlVector< FeSDFRigid_t > m_SDFRigids;
	CUtlVector< FeBoxRigid_t > m_BoxRigids;
	CUtlVector< uint8 > m_DynNodeVertexSet;
	CUtlVector< uint32 > m_VertexSetNames;
	CUtlVector< FeRigidColliderIndices_t > m_RigidColliderPriorities;
	CUtlVector< FeMorphLayerDepr_t > m_MorphLayers;
	CUtlVector< uint8 > m_MorphSetData;
	CUtlVector< FeVertexMapDesc_t > m_VertexMaps;
	CUtlVector< uint8 > m_VertexMapValues;
	CUtlVector< FeEffectDesc_t > m_Effects;
	CUtlVector< FeCtrlOffset_t > m_LockToParent;
	CUtlVector< uint16 > m_LockToGoal;
	CUtlVector< int16 > m_SkelParents;
	CUtlVector< FeNodeWindBase_t > m_DynNodeWindBases;
	float32 m_flInternalPressure;
	float32 m_flDefaultTimeDilation;
	float32 m_flWindage;
	float32 m_flWindDrag;
	float32 m_flDefaultSurfaceStretch;
	float32 m_flDefaultThreadStretch;
	float32 m_flDefaultGravityScale;
	float32 m_flDefaultVelAirDrag;
	float32 m_flDefaultExpAirDrag;
	float32 m_flDefaultVelQuadAirDrag;
	float32 m_flDefaultExpQuadAirDrag;
	float32 m_flRodVelocitySmoothRate;
	float32 m_flQuadVelocitySmoothRate;
	float32 m_flAddWorldCollisionRadius;
	float32 m_flDefaultVolumetricSolveAmount;
	float32 m_flMotionSmoothCDT;
	float32 m_flLocalDrag1;
	uint16 m_nRodVelocitySmoothIterations;
	uint16 m_nQuadVelocitySmoothIterations;
};