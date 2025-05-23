// MNetworkVarNames = "bool m_bIsUsable"
class CBaseDoor : public CBaseToggle
{
	QAngle m_angMoveEntitySpace;
	Vector m_vecMoveDirParentSpace;
	locksound_t m_ls;
	bool m_bForceClosed;
	bool m_bDoorGroup;
	bool m_bLocked;
	bool m_bIgnoreDebris;
	FuncDoorSpawnPos_t m_eSpawnPosition;
	float32 m_flBlockDamage;
	CUtlSymbolLarge m_NoiseMoving;
	CUtlSymbolLarge m_NoiseArrived;
	CUtlSymbolLarge m_NoiseMovingClosed;
	CUtlSymbolLarge m_NoiseArrivedClosed;
	CUtlSymbolLarge m_ChainTarget;
	CEntityIOOutput m_OnBlockedClosing;
	CEntityIOOutput m_OnBlockedOpening;
	CEntityIOOutput m_OnUnblockedClosing;
	CEntityIOOutput m_OnUnblockedOpening;
	CEntityIOOutput m_OnFullyClosed;
	CEntityIOOutput m_OnFullyOpen;
	CEntityIOOutput m_OnClose;
	CEntityIOOutput m_OnOpen;
	CEntityIOOutput m_OnLockedUse;
	bool m_bLoopMoveSound;
	bool m_bCreateNavObstacle;
	bool m_isChaining;
	// MNetworkEnable
	bool m_bIsUsable;
};
