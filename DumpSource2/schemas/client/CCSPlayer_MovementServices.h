// MNetworkVarNames = "Vector m_vecLadderNormal"
// MNetworkVarNames = "int m_nLadderSurfacePropIndex"
// MNetworkVarNames = "float m_flDuckAmount"
// MNetworkVarNames = "float m_flDuckSpeed"
// MNetworkVarNames = "bool m_bDuckOverride"
// MNetworkVarNames = "bool m_bDesiresDuck"
// MNetworkVarNames = "uint32 m_nDuckTimeMsecs"
// MNetworkVarNames = "uint32 m_nDuckJumpTimeMsecs"
// MNetworkVarNames = "uint32 m_nJumpTimeMsecs"
// MNetworkVarNames = "float m_flLastDuckTime"
// MNetworkVarNames = "int m_nGameCodeHasMovedPlayerAfterCommand"
// MNetworkVarNames = "bool m_bOldJumpPressed"
// MNetworkVarNames = "GameTime_t m_fStashGrenadeParameterWhen"
// MNetworkVarNames = "ButtonBitMask_t m_nButtonDownMaskPrev"
// MNetworkVarNames = "float m_flOffsetTickCompleteTime"
// MNetworkVarNames = "float m_flOffsetTickStashedSpeed"
// MNetworkVarNames = "float m_flStamina"
class CCSPlayer_MovementServices : public CPlayer_MovementServices_Humanoid
{
	// MNetworkEnable
	// MNetworkEncoder = "normal"
	Vector m_vecLadderNormal;
	// MNetworkEnable
	int32 m_nLadderSurfacePropIndex;
	// MNetworkEnable
	float32 m_flDuckAmount;
	// MNetworkEnable
	float32 m_flDuckSpeed;
	// MNetworkEnable
	bool m_bDuckOverride;
	// MNetworkEnable
	bool m_bDesiresDuck;
	float32 m_flDuckOffset;
	// MNetworkEnable
	// MNetworkUserGroup = "LocalPlayerExclusive"
	// MNetworkPriority = 32
	uint32 m_nDuckTimeMsecs;
	// MNetworkEnable
	// MNetworkUserGroup = "LocalPlayerExclusive"
	uint32 m_nDuckJumpTimeMsecs;
	// MNetworkEnable
	// MNetworkUserGroup = "LocalPlayerExclusive"
	uint32 m_nJumpTimeMsecs;
	// MNetworkEnable
	// MNetworkUserGroup = "LocalPlayerExclusive"
	float32 m_flLastDuckTime;
	Vector2D m_vecLastPositionAtFullCrouchSpeed;
	bool m_duckUntilOnGround;
	bool m_bHasWalkMovedSinceLastJump;
	bool m_bInStuckTest;
	float32[64][2] m_flStuckCheckTime;
	int32 m_nTraceCount;
	int32 m_StuckLast;
	bool m_bSpeedCropped;
	float32 m_flGroundMoveEfficiency;
	int32 m_nOldWaterLevel;
	float32 m_flWaterEntryTime;
	Vector m_vecForward;
	Vector m_vecLeft;
	Vector m_vecUp;
	// MNetworkEnable
	// MNetworkUserGroup = "LocalPlayerExclusive"
	int32 m_nGameCodeHasMovedPlayerAfterCommand;
	// MNetworkEnable
	bool m_bOldJumpPressed;
	float32 m_flJumpPressedTime;
	// MNetworkEnable
	GameTime_t m_fStashGrenadeParameterWhen;
	// MNetworkEnable
	uint64 m_nButtonDownMaskPrev;
	// MNetworkEnable
	float32 m_flOffsetTickCompleteTime;
	// MNetworkEnable
	float32 m_flOffsetTickStashedSpeed;
	// MNetworkEnable
	float32 m_flStamina;
	float32 m_flHeightAtJumpStart;
	float32 m_flMaxJumpHeightThisJump;
	float32 m_flMaxJumpHeightLastJump;
	float32 m_flStaminaAtJumpStart;
	float32 m_flAccumulatedJumpError;
};
