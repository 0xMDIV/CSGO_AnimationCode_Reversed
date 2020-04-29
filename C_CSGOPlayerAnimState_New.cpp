
#pragma pack(push, 1)
class animstate_pose_param_cache_t
{
public:
	bool m_bInitialized; //0x0000
	char pad_01[3]; //0x0001
	int32_t m_iPoseParameter; //0x0004
	char* m_szPoseParameter; //0x0008

	void SetValue(CBaseEntity* pPlayer, float flValue);
	float GetValue(CBaseEntity* pPlayer);
	bool Init(CBaseEntity* pPlayer, char* name);
}; //Size: 0x000C
#pragma pack(pop)

#pragma pack(push, 1)
struct AimLayer
{
	float m_flUnknown0;
	float m_flTotalTime;
	float m_flUnknown1;
	float m_flUnknown2;
	float m_flWeight;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct AimLayers
{
	AimLayer layers[3];
};
#pragma pack(pop)


#pragma pack(push, 1)
struct C_CSGOPlayerAnimState
{
	void* vtable;
	bool m_bIsReset;
	bool m_bUnknownClientBool;
	char pad[2];
	int m_iSomeTickcount;
	float m_flFlashedStartTime;
	float m_flFlashedEndTime;
	AimLayers m_AimLayers;
	int m_nModelIndex;
	int m_iUnknownClientArr[3];
	CBaseEntity* pBaseEntity;
	CBaseCombatWeapon* pActiveWeapon;
	CBaseCombatWeapon* pLastActiveWeapon;
	float m_flLastClientSideAnimationUpdateTime;
	int32_t m_iLastClientSideAnimationUpdateFramecount;
	float m_flLastClientSideAnimationUpdateTimeDelta;
	float m_flEyeYaw;
	float m_flPitch;
	float m_flGoalFeetYaw;
	float m_flCurrentFeetYaw;
	float m_flCurrentMoveDirGoalFeetDelta;
	float m_flGoalMoveDirGoalFeetDelta;
	float m_flFeetVelDirDelta;
	float pad_0094;
	float m_flFeetCycle;
	float m_flFeetWeight;
	float m_fUnknown2;
	float m_fDuckAmount;
	float m_flHitGroundCycle;
	float m_fUnknown3;
	Vector m_vOrigin;
	Vector m_vLastOrigin;
	Vector m_vVelocity;
	Vector m_vVelocityNormalized;
	Vector m_vecLastAcceleratingVelocity;
	float m_flSpeed;
	float m_flAbsVelocityZ;
	float m_flSpeedNormalized;
	float m_flRunningSpeed;
	float m_flDuckingSpeed;
	float m_flTimeSinceStartedMoving;
	float m_flTimeSinceStoppedMoving;
	bool m_bOnGround;
	bool m_bInHitGroundAnimation;
	char pad_010A[2];
	float m_flNextLowerBodyYawUpdateTime;
	float m_flTotalTimeInAir;
	float m_flStartJumpZOrigin;
	float m_flHitGroundWeight;
	float m_flGroundFraction;
	bool m_bJust_Landed;
	bool m_bJust_LeftGround;
	char pad_0120[2];
	float m_flDuckRate;
	bool m_bOnLadder;
	char pad_0128[3];
	float m_flLadderCycle;
	float m_flLadderWeight;
	bool m_bNotRunning;
	char pad_0135[3];
	bool m_bInBalanceAdjust;
	char pad_0141[3];
	CUtlVectorSimple m_Modifiers;
	int gap148[1];
	float m_flTimeOfLastInjury;
	float m_flLastSetupLeanCurtime;
	Vector m_vecLastSetupLeanVelocity;
	Vector m_vecSetupLeanVelocityDelta;
	Vector m_vecSetupLeanVelocityInterpolated;
	float m_flLeanWeight;
	int m_iUnknownIntArr2[2];
	bool m_bFlashed;
	char m_bFlashedPad[3];
	float m_flStrafeWeight;
	int m_iUnknownint3;
	float m_flStrafeCycle;
	int m_iStrafeSequence;
	bool m_bStrafing;
	char m_bStrafingPad[3];
	float m_flTotalStrafeTime;
	int m_iUnknownInt4;
	bool m_bUnknownBool__;
	bool m_bIsAccelerating;
	char pad_01AE[2];
	animstate_pose_param_cache_t m_arrPoseParameters[20];
	int m_iUnknownClientInt__;
	float m_flVelocityUnknown;
	int m_iMoveState;
	float m_flMovePlaybackRate;
	float m_flUnknownFL0;
	float m_flUnknownFL;
	float m_flUnknownFL1;
	float m_flMinYawServer;
	float m_flMaxYawServer;
	float m_flMaximumPitchServer;
	float m_flMinimumPitchServer;
	int m_iUnknownInt;
	char pad_02D0[84];
	float m_flEyePosZ;
	bool m_bIsDucked;
	char pad_0329[3];
	float m_flUnknownCap1;
	float m_flMinYaw;
	float m_flMaxYaw;
	float m_flMinPitch;
	float m_flMaxPitch;
	int m_iAnimsetVersion;

	C_AnimationLayer* GetAnimOverlay(int layer);
	void IncrementLayerCycle(int layer, bool dont_clamp_cycle);
	void IncrementLayerCycleGeneric(int layer);
	void LayerWeightAdvance(int layer);
	void SetFeetCycle(float cycle);
	int GetLayerActivity(int layer);
	void Update(float yaw, float pitch);
	void SetupFlinch();
	void SetupAliveloop();
	void SetupFlashedReaction();
	void SetupWholeBodyAction();
	void SetupMovement();
	void SetupLean();
	void SetupWeaponAction();
	void SetupAimMatrix();
	void SetupVelocity();
	bool CacheSequences();
	void SetLayerCycle(int layer, float cycle);
	void SetLayerWeight(int layer, float weight);
	void SetLayerSequence(int layer, int sequence);
	float GetLayerCycle(int layer);
	float GetLayerWeight(int layer);
	char* GetWeaponMoveAnimation();
	void UpdateAnimLayer(float playbackrate, int layer, int sequence, float weight, float cycle);
	void UpdateLayerOrderPreset(float weight, int layer, int sequence);
	float GetLayerIdealWeightFromSeqCycle(int layer);
	void UpdateAimLayer(AimLayer *layer, float timedelta, float multiplier, bool somebool);
};
#pragma pack(pop)


CStudioHdr::CActivityToSequenceMapping* FindMapping(CStudioHdr* hdr)
{
	//TODO: move to NetworkedVariables.cpp
	//decrypts(0)
	static DWORD adr = FindMemoryPattern(ClientHandle, XorStr("55  8B  EC  83  E4  F8  81  EC  ??  ??  ??  ??  53  56  57  8B  F9  8B  17  83  BA  ??  ??  ??  ??  ??  74  34  83  7F  04  00  75  2E  83  BA  ??  ??  ??  ??  ??  75  04  33  C0  EB  0C  8B  0D  ??  ??  ??  ??  52  8B  01  FF  50  68"));
	//encrypts(0)
	if (!adr)
		exit(EXIT_SUCCESS);

	return ((CStudioHdr::CActivityToSequenceMapping*(__thiscall*)(CStudioHdr*))adr)(hdr);
}

CStudioHdr::CActivityToSequenceMapping* getEmptyMapping()
{
	//TODO: move to NetworkedVariables.cpp
	//decrypts(0)
	static DWORD adr = FindMemoryPattern(ClientHandle, XorStr("87  0A  5F  5E  5B  8B  E5  5D  C3  B8  ??  ??  ??  ??  5F  5E  5B  8B  E5  5D  C3"));
	//encrypts(0)
	if (!adr)
		exit(EXIT_SUCCESS);
	static DWORD offset = NULL;
	if (!offset)
	{
		offset = *(DWORD*)(adr + 10);
	}
	return (CStudioHdr::CActivityToSequenceMapping*)offset;
}

int CBaseEntity::SelectWeightedSequenceFromModifiers(int activity, CUtlSymbol *pActivityModifiers, int iModifierCount)
{
	CStudioHdr *pstudiohdr = GetModelPtr();
	if (!pstudiohdr || !pstudiohdr->m_pVModel)
		pstudiohdr = nullptr;

	if (!pstudiohdr->m_pActivityToSequence)
		pstudiohdr->m_pActivityToSequence = FindMapping(pstudiohdr);

	return pstudiohdr->m_pActivityToSequence->SelectWeightedSequenceFromModifiers(pstudiohdr, activity, pActivityModifiers, iModifierCount, this);
}

bool IsInPrediction()
{
	CBaseEntity** pPredictionPlayer = StaticOffsets.GetOffsetValueByType<CBaseEntity**>(_predictionplayer);
	return *pPredictionPlayer != NULL;
}

//static CStudioHdr::CActivityToSequenceMapping emptyMapping;

// double-check that the data I point to hasn't changed
bool CStudioHdr::CActivityToSequenceMapping::ValidateAgainst(const CStudioHdr * __restrict pstudiohdr) __restrict
{
	return (this == /*&emptyMapping*/getEmptyMapping() ||
		(m_pStudioHdr == pstudiohdr->_m_pStudioHdr && m_expectedVModel == pstudiohdr->GetVirtualModel()));
}

/// Force Initialize() to occur again, even if it has already occured.
void CStudioHdr::CActivityToSequenceMapping::Reinitialize(CStudioHdr *pstudiohdr)
{
	StaticOffsets.GetOffsetValueByType<void(__thiscall*)(CStudioHdr::CActivityToSequenceMapping*, CStudioHdr*)>(_CActivityToSequenceMapping_Reinitialize)(this, pstudiohdr);
}

void IndexModelSequences(CStudioHdr *pstudiohdr)
{
	StaticOffsets.GetOffsetValueByType<void(__thiscall*)(CStudioHdr*)>(_IndexModelSequences)(pstudiohdr);
}

void VerifySequenceIndex(CStudioHdr *pstudiohdr)
{
	if (!pstudiohdr)
	{
		return;
	}

	if (pstudiohdr->GetActivityListVersion() < *StaticOffsets.GetOffsetValueByType<int*>(_g_nActivityListVersion))
	{
		// this model's sequences have not yet been indexed by activity
		IndexModelSequences(pstudiohdr);
	}
}

int CStudioHdr::CActivityToSequenceMapping::SelectWeightedSequence(CStudioHdr *pstudiohdr, int activity, int curSequence)
{
	return StaticOffsets.GetOffsetValueByType<int(__thiscall*)(CStudioHdr::CActivityToSequenceMapping*, CStudioHdr*, int, int)>(_SelectWeightedSequence)(this, pstudiohdr, activity, curSequence);
}

//NOTE: parent wasn't an activity but cba to rebuild GetSequenceActivity yet
int CStudioHdr::CActivityToSequenceMapping::SelectWeightedSequenceFromModifiers(CStudioHdr *pstudiohdr, int activity, CUtlSymbol *pActivityModifiers, int iModifierCount, CBaseEntity* parent)
{
	if (!pstudiohdr->SequencesAvailable())
	{
		return -1;
	}

	VerifySequenceIndex(pstudiohdr);

	if (pstudiohdr->GetNumSeq() == 1)
	{
		return (GetSequenceActivity(parent, 0) == activity) ? 0 : -1;
	}
	
	//added in nov 18, 2019 patch
	if (!iModifierCount)
		return SelectWeightedSequence(pstudiohdr, activity, -1);
	
	if (!ValidateAgainst(pstudiohdr))
	{
#ifdef _DEBUG
		if (IsDebuggerPresent())
			DebugBreak();
#endif
		//AssertMsg1(false, "CStudioHdr %s has changed its vmodel pointer without reinitializing its activity mapping! Now performing emergency reinitialization.", pstudiohdr->pszName());
		//ExecuteOnce(DebuggerBreakIfDebugging());
		Reinitialize(pstudiohdr);
	}

	// a null m_pSequenceTuples just means that this studio header has no activities.
	if (!m_pSequenceTuples)
		return -1;

	// get the data for the given activity
	HashValueType dummy(activity, 0, 0, 0);
	UtlHashHandle_t handle = m_ActToSeqHash.Find(dummy);
	if (!m_ActToSeqHash.IsValidHandle(handle))
		return -1;

	const HashValueType * __restrict actData = &m_ActToSeqHash[handle];

	// go through each sequence and give it a score
	CUtlVector<int> topScoring(actData->count, actData->count);
#if 1
	int local_8 = -1;
	if (actData->count > 0)
	{
		int topScoringCount = topScoring.Count();
		bool bFoundMatchingModifier = false;

		for (int i = 0; i < actData->count; ++i)
		{
			int k = 0;
			int iVar8 = 0;
			SequenceTuple * __restrict sequenceInfo = m_pSequenceTuples + actData->startingIdx + i;
			if (0 < sequenceInfo->iNumActivityModifiers)
			{
				for (int k = 0; k < sequenceInfo->iNumActivityModifiers; ++k)
				{
					bFoundMatchingModifier = false;
					if (0 < iModifierCount)
					{
						for (int m = 0; m < iModifierCount; ++m)
						{
							if (sequenceInfo->pActivityModifiers[k] == pActivityModifiers[m])
							{
								bFoundMatchingModifier = true;
								break;
							}
						};
					}
					int iUnknown = sequenceInfo->iUnknown[k];
					if (iUnknown == 0)
					{
						iUnknown = -1;
					LAB_101b07e7:
						if (bFoundMatchingModifier)
						{
							iUnknown = 2;
						}
					LAB_101b07f1:
						iVar8 = iVar8 + iUnknown;
					}
					else
					{
						if (iUnknown == 1)
						{
							iUnknown = 0;
							goto LAB_101b07e7;
						}
						if (iUnknown == 2)
						{
							iUnknown = (uint)bFoundMatchingModifier - 1;
							goto LAB_101b07f1;
						}
						if (iUnknown == 3)
						{
							bFoundMatchingModifier = (bool)(bFoundMatchingModifier ^ 1);
						LAB_101b07fe:
							if (bFoundMatchingModifier) goto LAB_101b0863;
							break;
						}
						if (iUnknown == 4) goto LAB_101b07fe;
					}
				}
			}
			if (local_8 <= iVar8)
			{
				if (local_8 < iVar8)
					topScoringCount = 0;

				topScoring.SetSizeDirect(topScoringCount);
				//VALVE IS DOING THIS FOR SOME REASON, MEMORY LEAK!!!!!!!!!

				local_8 = iVar8;
				if (0 < sequenceInfo->weight)
				{
					for (int w = 0; w < sequenceInfo->weight; ++w)
					{
						topScoring.AddToTail(sequenceInfo->seqnum);
					}
					topScoringCount = topScoring.Count();
				}
			}
		LAB_101b0863:
			int nig;
		}
	}

	if (topScoring.Count())
		return topScoring[RandomInt(0, topScoring.Count() - 1)];

	return -1;

#else
	for (int i = 0; i < actData->count; i++)
	{
		SequenceTuple * __restrict sequenceInfo = m_pSequenceTuples + actData->startingIdx + i;
		int score = 0;
		// count matching activity modifiers
		for (int iUnknown = 0; iUnknown < iModifierCount; iUnknown++)
		{
			int num_modifiers = sequenceInfo->iNumActivityModifiers;
			for (int k = 0; k < num_modifiers; k++)
			{
				if (sequenceInfo->pActivityModifiers[k] == pActivityModifiers[iUnknown])
				{
					score++;
					break;
				}
			}
		}
		if (score > top_score)
		{
			topScoring.RemoveAll();
			topScoring.AddToTail(sequenceInfo->seqnum);
			top_score = score;
		}
	}

	// randomly pick between the highest scoring sequences ( NOTE: this method of selecting a sequence ignores activity weights )
	//FIXME
	//if (IsInPrediction())
	//{
	//	return topScoring[SharedRandomInt("SelectWeightedSequence", 0, topScoring.Count() - 1)];
	//}
	return topScoring[RandomInt(0, topScoring.Count() - 1)];
#endif
}

bool animstate_pose_param_cache_t::Init(CBaseEntity* pPlayer, char* name)
{
	Interfaces::MDLCache->BeginLock();
	m_szPoseParameter = name;
	int pose_index	= pPlayer->LookupPoseParameter(pPlayer->GetModelPtr(), name);
	m_iPoseParameter  = pose_index;
	if (pose_index != -1)
		m_bInitialized = true;
	Interfaces::MDLCache->EndLock();
	return m_bInitialized;
}

void animstate_pose_param_cache_t::SetValue(CBaseEntity* pPlayer, float flValue)
{
	bool initialized = m_bInitialized;

	if (!m_bInitialized)
		initialized = Init(pPlayer, m_szPoseParameter);

	if (initialized && pPlayer)
	{
		Interfaces::MDLCache->BeginLock();
		pPlayer->SetPoseParameterGame(pPlayer->GetModelPtr(), flValue, m_iPoseParameter);
		Interfaces::MDLCache->EndLock();
	}
}

float animstate_pose_param_cache_t::GetValue(CBaseEntity *pPlayer)
{
	if (!m_bInitialized)
		Init(pPlayer, m_szPoseParameter);

	if (m_bInitialized && pPlayer)
		return pPlayer->GetPoseParameter(m_iPoseParameter);
	
	return 0.0f;
}

void C_CSGOPlayerAnimState::IncrementLayerCycle(int layer, bool dont_clamp_cycle)
{
	C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(layer);
	if (!pLayer || fabs(pLayer->_m_flPlaybackRate) <= 0.0f)
		return;

	float newcycle = (pLayer->_m_flPlaybackRate * m_flLastClientSideAnimationUpdateTimeDelta) + pLayer->_m_flCycle;

	if (!dont_clamp_cycle && newcycle >= 1.0f)
		newcycle = 0.999f;

	newcycle -= (float)(int)newcycle; //round to integer

	if (newcycle < 0.0f)
		newcycle += 1.0f;

	if (newcycle > 1.0f)
		newcycle -= 1.0f;

	pLayer->SetCycle(newcycle);
}

void C_CSGOPlayerAnimState::SetFeetCycle(float cycle)
{
	cycle -= (float)(int)cycle; //round to integer

	if (cycle < 0.0f)
		cycle += 1.0f;

	if (cycle > 1.0f)
		cycle -= 1.0f;

	m_flFeetCycle = cycle;
}

void C_CSGOPlayerAnimState::SetLayerCycle(int layer, float cycle)
{
	C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(layer);
	if (!pLayer)
		return;

	cycle -= (float)(int)cycle; //round to integer

	if (cycle < 0.0f)
		cycle += 1.0f;

	if (cycle > 1.0f)
		cycle -= 1.0f;

	pLayer->SetCycle(cycle);
}

void C_CSGOPlayerAnimState::SetLayerWeight(int layer, float weight)
{
	C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(layer);
	if (!pLayer)
		return;

	weight = clamp(weight, 0.0f, 1.0f);

	pLayer->SetWeight(weight);
}

void C_CSGOPlayerAnimState::SetLayerSequence(int layer, int sequence)
{
	if (sequence >= 2)
	{
		Interfaces::MDLCache->BeginLock();
		C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(layer);
		if (pLayer)
		{
			pLayer->SetSequence(sequence);
			pLayer->_m_flPlaybackRate = pBaseEntity->GetLayerSequenceCycleRate(pLayer, sequence);
			pLayer->SetCycle(0.0f);
			pLayer->SetWeight(0.0f);
			UpdateLayerOrderPreset(0.0f, layer, sequence);
		}
		Interfaces::MDLCache->EndLock();
	}
}

float C_CSGOPlayerAnimState::GetLayerCycle(int layer)
{
	C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(layer);
	if (!pLayer)
		return 0.0f;

	return pLayer->_m_flCycle;
}

float C_CSGOPlayerAnimState::GetLayerWeight(int layer)
{
	C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(layer);
	if (!pLayer)
		return 0.0f;

	return pLayer->m_flWeight;
}

void C_CSGOPlayerAnimState::IncrementLayerCycleGeneric(int layer)
{
	C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(layer);
	if (!pLayer || fabs(pLayer->_m_flPlaybackRate) <= 0.0f)
		return;

	float newcycle = (pLayer->_m_flPlaybackRate * m_flLastClientSideAnimationUpdateTimeDelta) + pLayer->_m_flCycle;

	newcycle -= newcycle;

	if (newcycle < 0.0f)
		newcycle += 1.0f;

	if (newcycle > 1.0f)
		newcycle -= 1.0f;

	pLayer->SetCycle(newcycle);
}

void C_CSGOPlayerAnimState::SetupWeaponAction()
{
	//((void(__thiscall*)(C_CSGOPlayerAnimState*))StaticOffsets.GetOffsetValue(_SetupWeaponAction))(this);

	C_AnimationLayer *layer1 = pBaseEntity->GetAnimOverlay(1);
	if (layer1)
	{
		if (layer1->m_flWeight > 0.0f)
		{
			IncrementLayerCycle(1, false);
			LayerWeightAdvance(1);
		}

		if (pActiveWeapon)
		{
			CBaseEntity* worldmodel = Interfaces::ClientEntList->GetBaseEntityFromHandle(pActiveWeapon->GetWorldModelHandle());
			if (worldmodel)
			{
				Interfaces::MDLCache->BeginLock();
				if (layer1->m_iPriority <= 0 || layer1->m_flWeight <= 0.0f)
				{
					worldmodel->SetSequenceVMT(0);
					worldmodel->SetCycle(0.0f);
					worldmodel->SetPlaybackRate(0.0f);
				}
				else
				{
					worldmodel->SetSequenceVMT(layer1->m_iPriority);
					worldmodel->SetCycle(layer1->_m_flCycle);
					worldmodel->SetPlaybackRate(layer1->_m_flPlaybackRate);
				}
				Interfaces::MDLCache->EndLock();
			}
		}
	}
}

void C_CSGOPlayerAnimState::UpdateAimLayer(AimLayer *array, float timedelta, float multiplier, bool somebool)
{
	float v4;
	bool v5;
	float v7;
	float v8;

	if (somebool)
	{
		v4 = array->m_flUnknown0 + timedelta;
		array->m_flTotalTime = 0.0;
		v5 = v4 < array->m_flUnknown1;
		array->m_flUnknown0 = v4;

		if (v5)
			return;

		if ((1.0f - array->m_flWeight) <= multiplier)
		{
			if (-multiplier <= (1.0f - array->m_flWeight))
			{
				array->m_flWeight = 1.0f;
				return;
			}
			array->m_flWeight = array->m_flWeight - multiplier;
			return;
		}
		array->m_flWeight = array->m_flWeight + multiplier;
		return;
	}

	v7 = array->m_flTotalTime + timedelta;
	array->m_flUnknown0 = 0.0;
	v5 = v7 < array->m_flUnknown2;
	array->m_flTotalTime = v7;

	if (v5)
		return;

	if (-array->m_flWeight > multiplier)
	{
		array->m_flWeight = array->m_flWeight + multiplier;
		return;
	}

	if (-multiplier > -array->m_flWeight)
	{
		array->m_flWeight = array->m_flWeight - multiplier;
		return;
	}
	array->m_flWeight = 0.0;
}

void C_CSGOPlayerAnimState::SetupAimMatrix()
{
	START_PROFILING
#ifdef _DEBUG
	((void(__thiscall*)(C_CSGOPlayerAnimState*))StaticOffsets.GetOffsetValue(_SetupAimMatrix))(this);
	END_PROFILING;
	return;
#endif

	Interfaces::MDLCache->BeginLock();
	if (m_fDuckAmount <= 0.0f || m_fDuckAmount >= 1.0f)
	{
		bool is_walking = pBaseEntity && pBaseEntity->GetIsWalking();
		bool is_scoped;
		float speedmultiplier;
		if (pBaseEntity && pBaseEntity->IsScoped())
		{
			speedmultiplier = 4.2f;
			is_scoped = true;
		}
		else
		{
			speedmultiplier = 0.8f;
			is_scoped = false;
		}

		speedmultiplier *= m_flLastClientSideAnimationUpdateTimeDelta;

		if (is_scoped)
		{
			m_AimLayers.layers[0].m_flTotalTime = m_AimLayers.layers[0].m_flUnknown2;
			m_AimLayers.layers[1].m_flTotalTime = m_AimLayers.layers[1].m_flUnknown2;
			m_AimLayers.layers[2].m_flTotalTime = m_AimLayers.layers[2].m_flUnknown2;
		}

		bool v10 = is_walking && !is_scoped && m_flRunningSpeed > 0.7f && m_flSpeedNormalized < 0.7f;
		UpdateAimLayer(m_AimLayers.layers, m_flLastClientSideAnimationUpdateTimeDelta, speedmultiplier, v10);

		bool v12 = !is_scoped && m_flSpeedNormalized >= 0.7;
		UpdateAimLayer(&m_AimLayers.layers[1], m_flLastClientSideAnimationUpdateTimeDelta, speedmultiplier, v12);

		bool v14 = !is_scoped && m_flDuckingSpeed >= 0.5;
		UpdateAimLayer(&m_AimLayers.layers[2], m_flLastClientSideAnimationUpdateTimeDelta, speedmultiplier, v14);
	}

	float pose_crouch_idle = 1.0f;
	float strafe_weight = 1.0f;
	float aimlayer0_weight = m_AimLayers.layers[0].m_flWeight;
	float aimlayer1_weight = m_AimLayers.layers[1].m_flWeight;
	float aimlayer2_weight = m_AimLayers.layers[2].m_flWeight;
	if (aimlayer0_weight >= 1.0f)
		pose_crouch_idle = 0.0f;
	if (aimlayer1_weight >= 1.0f)
	{
		pose_crouch_idle = 0.0f;
		aimlayer0_weight = 0.0;
	}
	if (aimlayer2_weight >= 1.0f)
	{
		strafe_weight = 0.0f;
	}
	if (m_fDuckAmount < 1.0f)
	{
		if (m_fDuckAmount <= 0.0f)
		{
			strafe_weight = 0.0f;
			aimlayer2_weight = 0.0f;
		}
	}
	else
	{
		pose_crouch_idle = 0.0f;
		aimlayer0_weight = 0.0f;
		aimlayer1_weight = 0.0f;
	}

	float duck_pose = 1.0f - m_fDuckAmount;
	float pose_strafe_yaw = m_fDuckAmount * strafe_weight;
	float pose_move_blend_walk = m_fDuckAmount * aimlayer2_weight;

	float pose_stand_run = duck_pose * aimlayer0_weight;
	float pose_crouch_walk = duck_pose * aimlayer1_weight;

	if (pose_strafe_yaw < 1.0f && pose_move_blend_walk < 1.0f && pose_stand_run < 1.0f && pose_crouch_walk < 1.0f)
	{
		pose_crouch_idle = 1.0f;
	}

	m_arrPoseParameters[11].SetValue(pBaseEntity, pose_crouch_idle); //aim_blend_crouch_idle
	m_arrPoseParameters[14].SetValue(pBaseEntity, pose_stand_run); //aim_blend_stand_run
	m_arrPoseParameters[15].SetValue(pBaseEntity, pose_crouch_walk); //aim_blend_crouch_walk
	m_arrPoseParameters[12].SetValue(pBaseEntity, pose_strafe_yaw); //strafe_yaw
	m_arrPoseParameters[16].SetValue(pBaseEntity, pose_move_blend_walk); //move_blend_walk

	char animation[64];
	//decrypts(0)
	sprintf_s(animation, XorStr("%s_aim"), GetWeaponMoveAnimation());
	//encrypts(0)

	int aim_sequence = pBaseEntity->LookupSequence(animation);
	C_AnimationLayer *layer0 = pBaseEntity->GetAnimOverlay(0);
	if (layer0)
	{
		if (pActiveWeapon)
		{
			CBaseEntity* worldmodel = Interfaces::ClientEntList->GetBaseEntityFromHandle(pActiveWeapon->GetWorldModelHandle());
			CBaseEntity* sourcemodel = pBaseEntity;
			int sourcesequence = aim_sequence;
			if (worldmodel && layer0->m_iPriority != -1)
			{
				sourcemodel = worldmodel;
				sourcesequence = layer0->m_iPriority;
			}

			if (sourcesequence > 0)
			{
				float yawmin_idle = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMIN_IDLE, -58.0f);
				float yawmax_idle = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMAX_IDLE, 58.0f);
				float yawmin_walk = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMIN_WALK, yawmin_idle);
				float yawmax_walk = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMAX_WALK, yawmax_idle);
				float yawmin_run = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMIN_RUN, yawmin_walk);
				float yawmax_run = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMAX_RUN, yawmax_walk);
				float yawmin_crouchidle = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMIN_CROUCHIDLE, -58.0f);
				float yawmax_crouchidle = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMAX_CROUCHIDLE, 58.0f);
				float yawmin_crouchwalk = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMIN_CROUCHWALK, yawmin_crouchidle);
				float yawmax_crouchwalk = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_YAWMAX_CROUCHWALK, yawmax_crouchidle);

				float pose_blend_stand_run = m_arrPoseParameters[14].GetValue(pBaseEntity); //aim_blend_stand_run
				float pose_blend_crouch_walk = m_arrPoseParameters[15].GetValue(pBaseEntity); //aim_blend_crouch_walk
				pose_move_blend_walk = m_arrPoseParameters[16].GetValue(pBaseEntity); //move_blend_walk

				if (!pBaseEntity)
				{
					pose_move_blend_walk = 0.0f;
				}

				float v62 = ((yawmax_crouchwalk - yawmax_crouchidle) * pose_move_blend_walk) + yawmax_crouchidle;
				float v63 = ((yawmin_run - (((yawmin_walk - yawmin_idle) * pose_blend_stand_run) + yawmin_idle)) * pose_blend_crouch_walk)
					+ (((yawmin_walk - yawmin_idle) * pose_blend_stand_run) + yawmin_idle);

				m_flMinYaw = (((((yawmin_crouchwalk - yawmin_crouchidle) * pose_move_blend_walk) + yawmin_crouchidle)
					- v63)
					* m_fDuckAmount)
					+ v63;

				m_flMaxYaw = ((v62
					- (((yawmax_run
						- (((yawmax_walk - yawmax_idle) * pose_blend_stand_run) + yawmax_idle))
						* pose_blend_crouch_walk)
						+ (((yawmax_walk - yawmax_idle) * pose_blend_stand_run) + yawmax_idle)))
					* m_fDuckAmount)
					+ (((yawmax_run
						- (((yawmax_walk - yawmax_idle) * pose_blend_stand_run) + yawmax_idle))
						* pose_blend_crouch_walk)
						+ (((yawmax_walk - yawmax_idle) * pose_blend_stand_run) + yawmax_idle));

				float pitchmin_idle = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_PITCHMIN_IDLE, -90.0f);
				float pitchmax_idle = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_PITCHMAX_IDLE, 90.0f);
				float pitchmin_walkrun = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_PITCHMIN_WALKRUN, pitchmin_idle);
				float pitchmax_walkrun = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_PITCHMAX_WALKRUN, pitchmax_idle);
				float pitchmin_crouch = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_PITCHMIN_CROUCH, -90.0f);
				float pitchmax_crouch = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_PITCHMAX_CROUCH, 90.0f);
				float pitchmin_crouchwalk = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_PITCHMIN_CROUCHWALK, pitchmin_crouch);
				float pitchmax_crouchwalk = sourcemodel->GetAnySequenceAnimTag(sourcesequence, ANIMTAG_AIMLIMIT_PITCHMAX_CROUCHWALK, pitchmax_crouch);

				float v67 = (((((pitchmax_crouchwalk - pitchmax_crouch) * pose_move_blend_walk) + pitchmax_crouch)
					- (((pitchmax_walkrun - pitchmax_idle) * pose_blend_stand_run) + pitchmax_idle))
					* m_fDuckAmount)
					+ (((pitchmax_walkrun - pitchmax_idle) * pose_blend_stand_run) + pitchmax_idle);

				m_flMinPitch = (((((pitchmin_crouchwalk - pitchmin_crouch) * pose_move_blend_walk) + pitchmin_crouch)
					- (((pitchmin_walkrun - pitchmin_idle) * pose_blend_stand_run)
						+ pitchmin_idle))
					* m_fDuckAmount)
					+ (((pitchmin_walkrun - pitchmin_idle) * pose_blend_stand_run)
						+ pitchmin_idle);

				m_flMaxPitch = v67;
			}
		}
	}

	UpdateAnimLayer(0.0f, 0, aim_sequence, 1.0f, 0.0f);

	Interfaces::MDLCache->EndLock();
	END_PROFILING
}

void C_CSGOPlayerAnimState::SetupLean()
{
	START_PROFILING
#ifdef _DEBUG
	((void(__thiscall*)(C_CSGOPlayerAnimState*))StaticOffsets.GetOffsetValue(_SetupLean))(this);
	END_PROFILING
	return;
#endif

	float timedelta = Interfaces::Globals->curtime - m_flLastSetupLeanCurtime;
	if (timedelta > 0.025f)
	{
		if (timedelta >= 0.1f)
			timedelta = 0.1f;

		Vector vecVelocity = pBaseEntity->GetVelocity();
		m_flLastSetupLeanCurtime = Interfaces::Globals->curtime;
		m_vecSetupLeanVelocityDelta.x = (vecVelocity.x - m_vecLastSetupLeanVelocity.x) * (1.0f / timedelta);
		m_vecSetupLeanVelocityDelta.y = (vecVelocity.y - m_vecLastSetupLeanVelocity.y) * (1.0f / timedelta);
		m_vecSetupLeanVelocityDelta.z = 0.0f;
		m_vecLastSetupLeanVelocity = vecVelocity;
	}
	
	m_vecSetupLeanVelocityInterpolated = g_LagCompensation.GetSmoothedVelocity(m_flLastClientSideAnimationUpdateTimeDelta * 800.0f, m_vecSetupLeanVelocityDelta, m_vecSetupLeanVelocityInterpolated);

	Vector pseudoup = Vector(0.0f, 0.0f, 1.0f);
	QAngle angles;
	VectorAngles(m_vecSetupLeanVelocityInterpolated, pseudoup, angles);

	float speed = (m_vecSetupLeanVelocityInterpolated.Length() * (1.0f / _CS_PLAYER_SPEED_RUN)) * m_flSpeedNormalized;

	//*(float *)&animstate->m_bNotRunning ON SERVER
	m_flLeanWeight = (1.0f - m_flLadderCycle) * clamp(speed, 0.0f, 1.0f);

	float flGoalFeetLeanDelta = AngleNormalize(m_flGoalFeetYaw - angles.y);
	
	m_arrPoseParameters[0].SetValue(pBaseEntity, flGoalFeetLeanDelta);

	C_AnimationLayer *layer12 = pBaseEntity->GetAnimOverlay(12);
	if (!layer12 || layer12->_m_nSequence <= 0)
	{
		Interfaces::MDLCache->BeginLock();
		//decrypts(0)
		int seq = pBaseEntity->LookupSequence(XorStr("lean"));
		//encrypts(0)
		SetLayerSequence(12, seq);
		Interfaces::MDLCache->EndLock();
	}

	SetLayerWeight(12, m_flLeanWeight);

	//Other shit is done here on the server
	END_PROFILING
}

char *leanyawstr = new char[9]{ 22, 31, 27, 20, 37, 3, 27, 13, 0 }; /*lean_yaw*/
char *speedstr = new char[6]{ 9, 10, 31, 31, 30, 0 }; /*speed*/
char *ladderspeedstr = new char[13]{ 22, 27, 30, 30, 31, 8, 37, 9, 10, 31, 31, 30, 0 }; /*ladder_speed*/
char *ladderyawstr = new char[11]{ 22, 27, 30, 30, 31, 8, 37, 3, 27, 13, 0 }; /*ladder_yaw*/
char *moveyawstr = new char[9]{ 23, 21, 12, 31, 37, 3, 27, 13, 0 }; /*move_yaw*/
char *runstr = new char[4]{ 8, 15, 20, 0 }; /*run*/
char *bodyyawstr = new char[9]{ 24, 21, 30, 3, 37, 3, 27, 13, 0 }; /*body_yaw*/
char *bodypitchstr = new char[11]{ 24, 21, 30, 3, 37, 10, 19, 14, 25, 18, 0 }; /*body_pitch*/
char *deathyawstr = new char[10]{ 30, 31, 27, 14, 18, 37, 3, 27, 13, 0 }; /*death_yaw*/
char *standstr = new char[6]{ 9, 14, 27, 20, 30, 0 }; /*stand*/
char *jumpfallstr = new char[10]{ 16, 15, 23, 10, 37, 28, 27, 22, 22, 0 }; /*jump_fall*/
char *aimblendstandidlestr = new char[21]{ 27, 19, 23, 37, 24, 22, 31, 20, 30, 37, 9, 14, 27, 20, 30, 37, 19, 30, 22, 31, 0 }; /*aim_blend_stand_idle*/
char *aimblendcrouchidlestr = new char[22]{ 27, 19, 23, 37, 24, 22, 31, 20, 30, 37, 25, 8, 21, 15, 25, 18, 37, 19, 30, 22, 31, 0 }; /*aim_blend_crouch_idle*/
char *strafeyawstr = new char[11]{ 9, 14, 8, 27, 28, 31, 37, 3, 27, 13, 0 }; /*strafe_yaw*/
char *aimblendstandwalkstr = new char[21]{ 27, 19, 23, 37, 24, 22, 31, 20, 30, 37, 9, 14, 27, 20, 30, 37, 13, 27, 22, 17, 0 }; /*aim_blend_stand_walk*/
char *aimblendstandrunstr = new char[20]{ 27, 19, 23, 37, 24, 22, 31, 20, 30, 37, 9, 14, 27, 20, 30, 37, 8, 15, 20, 0 }; /*aim_blend_stand_run*/
char *aimblendcrouchwalkstr = new char[22]{ 27, 19, 23, 37, 24, 22, 31, 20, 30, 37, 25, 8, 21, 15, 25, 18, 37, 13, 27, 22, 17, 0 }; /*aim_blend_crouch_walk*/
char *moveblendwalkstr = new char[16]{ 23, 21, 12, 31, 37, 24, 22, 31, 20, 30, 37, 13, 27, 22, 17, 0 }; /*move_blend_walk*/
char *moveblendrunstr = new char[15]{ 23, 21, 12, 31, 37, 24, 22, 31, 20, 30, 37, 8, 15, 20, 0 }; /*move_blend_run*/
char *moveblendcrouchstr = new char[18]{ 23, 21, 12, 31, 37, 24, 22, 31, 20, 30, 37, 25, 8, 21, 15, 25, 18, 0 }; /*move_blend_crouch*/
bool _didDecrypt = false;

bool C_CSGOPlayerAnimState::CacheSequences()
{
#ifdef _DEBUG
	return ((bool(__thiscall*)(C_CSGOPlayerAnimState*))StaticOffsets.GetOffsetValue(_CacheSequences))(this);
#else
	if (!pBaseEntity)
		return false;

	if (m_nModelIndex != pBaseEntity->GetModelIndex())
	{
		m_iAnimsetVersion = 0;

		CUtlBuffer buffer(1024, 0, CUtlBuffer::TEXT_BUFFER);
		//decrypts(0)
		buffer.PutString(XorStr("keyvalues {\n"));
		//encrypts(0)

		if (Interfaces::ModelInfoClient->GetModelKeyValue(pBaseEntity->GetModel(), buffer))
		{
			buffer.PutString("\n}");
			auto keyValues = new KeyValues("");
			if (keyValues)
			{
				if (keyValues->LoadFromBuffer(Interfaces::ModelInfoClient->GetModelName(pBaseEntity->GetModel()), buffer.String()))
				{
					//decrypts(0)
					for (KeyValues *sub = keyValues->GetFirstSubKey(); sub != NULL; sub = sub->GetNextKey())
					{
						if (sub->FindKey(XorStr("animset_version"), false))
						{
							m_iAnimsetVersion = sub->GetInt(XorStr("animset_version"), 2);
							break;
						}
					}
					//encrypts(0)
				}

				keyValues->deleteThis();
			}
		}

		if (!_didDecrypt)
		{

			DecStr(leanyawstr, 8);
			DecStr(speedstr, 5);
			DecStr(ladderspeedstr, 12);
			DecStr(ladderyawstr, 10);
			DecStr(moveyawstr, 8);
			DecStr(runstr, 3);
			DecStr(bodyyawstr, 8);
			DecStr(bodypitchstr, 10);
			DecStr(deathyawstr, 9);
			DecStr(standstr, 5);
			DecStr(jumpfallstr, 9);
			DecStr(aimblendstandidlestr, 20);
			DecStr(aimblendcrouchidlestr, 21);
			DecStr(strafeyawstr, 10);
			DecStr(aimblendstandwalkstr, 20);
			DecStr(aimblendstandrunstr, 19);
			DecStr(aimblendcrouchwalkstr, 21);
			DecStr(moveblendwalkstr, 15);
			DecStr(moveblendrunstr, 14);
			DecStr(moveblendcrouchstr, 17);
			_didDecrypt = true;
		}


		m_arrPoseParameters[0].Init(pBaseEntity, leanyawstr);
		m_arrPoseParameters[1].Init(pBaseEntity, speedstr);
		m_arrPoseParameters[2].Init(pBaseEntity, ladderspeedstr);
		m_arrPoseParameters[3].Init(pBaseEntity, ladderyawstr);
		m_arrPoseParameters[4].Init(pBaseEntity, moveyawstr);
		if (m_iAnimsetVersion < 2)
			m_arrPoseParameters[5].Init(pBaseEntity, runstr);
		m_arrPoseParameters[6].Init(pBaseEntity, bodyyawstr);
		m_arrPoseParameters[7].Init(pBaseEntity, bodypitchstr);
		m_arrPoseParameters[8].Init(pBaseEntity, deathyawstr);
		m_arrPoseParameters[9].Init(pBaseEntity, standstr);
		m_arrPoseParameters[10].Init(pBaseEntity, jumpfallstr);
		m_arrPoseParameters[11].Init(pBaseEntity, aimblendstandidlestr);
		m_arrPoseParameters[12].Init(pBaseEntity, aimblendcrouchidlestr);
		m_arrPoseParameters[13].Init(pBaseEntity, strafeyawstr);
		m_arrPoseParameters[14].Init(pBaseEntity, aimblendstandwalkstr);
		m_arrPoseParameters[15].Init(pBaseEntity, aimblendstandrunstr);
		m_arrPoseParameters[16].Init(pBaseEntity, aimblendcrouchwalkstr);
		if (m_iAnimsetVersion > 0)
		{
			m_arrPoseParameters[17].Init(pBaseEntity, moveblendwalkstr);
			m_arrPoseParameters[18].Init(pBaseEntity, moveblendrunstr);
			m_arrPoseParameters[19].Init(pBaseEntity, moveblendcrouchstr);
		}
		m_nModelIndex = pBaseEntity->GetModelIndex();
	}
	return m_nModelIndex > 0;
#endif
}

char* C_CSGOPlayerAnimState::GetWeaponMoveAnimation()
{
	return ((char*(__thiscall*)(C_CSGOPlayerAnimState*))StaticOffsets.GetOffsetValue(_GetWeaponMoveAnimation))(this);
}

bool IsPlayingOldDemo()
{
	return (Interfaces::EngineClient->IsHLTV() || Interfaces::EngineClient->IsPlayingDemo()) && Interfaces::EngineClient->GetEngineBuildNumber() <= 13546;
}

void C_CSGOPlayerAnimState::Update(float yaw, float pitch)
{
	if (!pBaseEntity || (!pBaseEntity->GetAliveVMT() && !pBaseEntity->IsPlayerGhost()) || !CacheSequences())
		return;

	START_PROFILING

	pitch = AngleNormalize(pBaseEntity->GetThirdPersonRecoil() + pitch);

	//if (m_flLastClientSideAnimationUpdateTime == Interfaces::Globals->curtime 
	//	|| m_iLastClientSideAnimationUpdateFramecount == Interfaces::Globals->framecount)
	//	return;

	*s_bEnableInvalidateBoneCache = false;

	m_flLastClientSideAnimationUpdateTimeDelta = fmaxf(Interfaces::Globals->curtime - m_flLastClientSideAnimationUpdateTime, 0.0f);
	m_flEyeYaw = AngleNormalize(yaw);
	m_flPitch = AngleNormalize(pitch);
	m_vOrigin = *pBaseEntity->GetAbsOrigin();
	pActiveWeapon = pBaseEntity->GetActiveCSWeapon();
	if (pActiveWeapon != pLastActiveWeapon || m_bIsReset)
	{
		for (int i = 0; i < 13; ++i)
		{
			C_AnimationLayer *layer = pBaseEntity->GetAnimOverlay(i);
			if (layer)
			{
				layer->_m_fFlags = 0;
				layer->m_iActivity = -1;
				layer->m_iPriority = -1;
			}
		}
	}

	float flNewDuckAmount;

	if (!IsPlayingOldDemo())
	{
		flNewDuckAmount = clamp(pBaseEntity->GetDuckAmount() + m_flHitGroundCycle, 0.0f, 1.0f);
		float flDuckSmooth = m_flLastClientSideAnimationUpdateTimeDelta * 6.0f;
		float flDuckDelta = flNewDuckAmount - m_fDuckAmount;

		if (flDuckDelta <= flDuckSmooth) {
			if (-flDuckSmooth > flDuckDelta)
				flNewDuckAmount = m_fDuckAmount - flDuckSmooth;
		}
		else {
			flNewDuckAmount = flDuckSmooth + m_fDuckAmount;
		}

		flNewDuckAmount = clamp(flNewDuckAmount, 0.0f, 1.0f);
	}
	else
	{
		float flLandingAdjustment;
		if (pBaseEntity->GetFlags() & FL_ANIMDUCKING)
			flLandingAdjustment = 1.0f;
		else
			flLandingAdjustment = m_flHitGroundCycle;

		float flLandTimeAdjust;
		if (flLandingAdjustment <= m_fDuckAmount)
			flLandTimeAdjust = 6.0f;
		else
			flLandTimeAdjust = 3.1f;

		float flNewTimeDelta = m_flLastClientSideAnimationUpdateTimeDelta * flLandTimeAdjust;
		if (flLandingAdjustment - m_fDuckAmount <= flNewTimeDelta)
		{
			if (-flNewTimeDelta <= flLandingAdjustment - m_fDuckAmount)
				flNewDuckAmount = flLandingAdjustment;
			else
				flNewDuckAmount = m_fDuckAmount - flNewTimeDelta;
		}
		else
		{
			flNewDuckAmount = m_fDuckAmount + flNewTimeDelta;
		}

		m_fDuckAmount = flNewDuckAmount;

		flNewDuckAmount = clamp(flNewDuckAmount, 0.0f, 1.0f);
	}

	m_fDuckAmount = flNewDuckAmount;

	Interfaces::MDLCache->BeginLock();
	pBaseEntity->SetSequenceVMT(0);
	pBaseEntity->SetPlaybackRate(0.0f);
	if (pBaseEntity->GetCycle() != 0.0f) //SetCycle inlined
	{
		pBaseEntity->SetCycle(0.0f);
		pBaseEntity->InvalidatePhysicsRecursive(ANIMATION_CHANGED);
	}
	Interfaces::MDLCache->EndLock();

	//char *sig = "55  8B  EC  83  E4  F8  83  EC  30  56  57  8B  3D  ??  ??  ??  ??  8B  F1  8B  CF  89  74  24  14  8B  07  FF  90  ??  ??  ??  ??  8B  0D  ??  ??  ??  ??  F3  0F  7E  86  ??  ??  ??  ??  8B  86  ??  ??  ??  ??  89  44  24  28  66  0F  D6  44  24  ??  8B  01  8B  80  ??  ??  ??  ??  FF  D0  84  C0  75  38  8B  0D  ??  ??  ??  ??  8B  01  8B  80  ??  ??  ??  ??";
	//static DWORD func = FindPattern(ClientHandle, std::string(sig), 0, false, 0, 0, 0, 0, 0, 4);
	//((void(__thiscall*)(C_CSGOPlayerAnimState*))func)(this);
	//StaticOffsets.GetOffsetValueByType<void(__thiscall*)(C_CSGOPlayerAnimState*)>(_SetupVelocity)(this);
	SetupVelocity();
	SetupAimMatrix();
	SetupWeaponAction();
#if 0
	PlayerBackup_t *backup = new PlayerBackup_t;
	PlayerBackup_t *backup2 = new PlayerBackup_t;
	PlayerBackup_t *backup3 = new PlayerBackup_t;
	backup->Get(pBaseEntity);

	((void(__thiscall*)(C_CSGOPlayerAnimState*))StaticOffsets.GetOffsetValue(_SetupMovement))(this);
	printf("correct layer5 weight: %f onground: %i feetweight: %f\n", pBaseEntity->GetAnimOverlay(5)->m_flWeight, m_bOnGround ? 1 : 0, m_flFeetWeight);
	backup2->Get(pBaseEntity);

	backup->RestoreData();
	SetupMovement();
	printf("bad layer5 weight: %f onground: %i feetweight: %f\n", pBaseEntity->GetAnimOverlay(5)->m_flWeight, m_bOnGround ? 1 : 0, m_flFeetWeight);
	backup3->Get(pBaseEntity);
	if (m_iStrafeSequence != backup2->m_BackupClientAnimState.m_iStrafeSequence)
	{
		printf("");
		backup->RestoreData();
		printf("call original\n");
		((void(__thiscall*)(C_CSGOPlayerAnimState*))StaticOffsets.GetOffsetValue(_SetupMovement))(this);
		backup->RestoreData();
		printf("call ours\n");
		SetupMovement();
	}
	backup2->RestoreData();

	

	C_CSGOPlayerAnimState *fucked = &backup3->m_BackupClientAnimState;
	C_CSGOPlayerAnimState *correct = &backup2->m_BackupClientAnimState;

	C_AnimationLayer *fuckedlayer5 = &backup3->m_AnimLayers[5];
	C_AnimationLayer *correctlayer5 = &backup2->m_AnimLayers[5];
	C_AnimationLayer *fuckedlayer4 = &backup3->m_AnimLayers[4];
	C_AnimationLayer *correctlayer4 = &backup2->m_AnimLayers[4];

	float correcttotaltime = backup2->m_BackupClientAnimState.m_flStrafeWeight;
	float fuckedtotaltime = backup3->m_BackupClientAnimState.m_flStrafeWeight;

	float correcttotaltime2 = backup2->m_BackupClientAnimState.m_flDuckRate;
	float fuckedtotaltime2 = backup3->m_BackupClientAnimState.m_flDuckRate;

	//backup2->backupanimstate.m_iStrafeSequence;
	//backup3->backupanimstate.m_iStrafeSequence;

	if (fuckedlayer5->m_flWeight != correctlayer5->m_flWeight)
		printf("");

	if (CurrentUserCmd.cmd && CurrentUserCmd.cmd->buttons & IN_SPEED)
		printf(" ");

	for (int i = 0; i < MAX_OVERLAYS; ++i)
	{
		if (fabsf(backup3->m_AnimLayers[i].m_flWeight - backup2->m_AnimLayers[i].m_flWeight) > FLT_EPSILON
			|| 
			fabsf(backup3->m_AnimLayers[i]._m_flCycle - backup2->m_AnimLayers[i]._m_flCycle) > FLT_EPSILON
			|| 
			fabsf(backup3->m_AnimLayers[i]._m_flPlaybackRate - backup2->m_AnimLayers[i]._m_flPlaybackRate) > FLT_EPSILON
			)
		{
			printf("");
		}
	}

	delete backup;
	delete backup2;
	delete backup3;
#else
	SetupMovement();
#endif
	SetupAliveloop();
	SetupWholeBodyAction();
	SetupFlashedReaction();
	SetupFlinch();
	SetupLean();

	for (int i = 0; i < 13; ++i)
	{
		C_AnimationLayer *layer = pBaseEntity->GetAnimOverlay(i);
		if (layer && !layer->_m_nSequence && layer->m_pOwner && layer->m_flWeight != 0.0f) //SetWeight inlined
		{
			layer->m_pOwner->InvalidatePhysicsRecursive(BOUNDS_CHANGED);
			layer->m_flWeight = 0.0f;
		}
	}

	pBaseEntity->SetAbsAngles(QAngle(0.0f, m_flGoalFeetYaw, 0.0f));
	pLastActiveWeapon = pActiveWeapon;
	m_vLastOrigin = m_vOrigin;
	m_bIsReset = 0;
	m_flLastClientSideAnimationUpdateTime = Interfaces::Globals->curtime;
	m_iLastClientSideAnimationUpdateFramecount = Interfaces::Globals->framecount;
	*s_bEnableInvalidateBoneCache = true;
	END_PROFILING
}

void C_CSGOPlayerAnimState::SetupVelocity()
{
	START_PROFILING
	Interfaces::MDLCache->BeginLock();

	Vector velocity = m_vVelocity;
	//if (Interfaces::EngineClient->IsHLTV() || Interfaces::EngineClient->IsPlayingDemo())
		pBaseEntity->GetAbsVelocity(velocity);
	//else
	//	pBaseEntity->EstimateAbsVelocity(velocity);

	float spd = velocity.LengthSqr();

	// Valve's bandaid for when players respawn or come in from dormancy. Fixes legs facing the wrong direction as soon as they spawn due to velocity being huge due to origin delta
	//if (spd > std::pow(1.2f * 260.0f, 2))
	//{
	//	Vector velocity_normalized = velocity;
	//	VectorNormalizeFast(velocity_normalized);
	//	velocity = velocity_normalized * (1.2f * 260.0f);
	//}

	m_flAbsVelocityZ = velocity.z;
	velocity.z = 0.0f;

	float leanspd = m_vecLastSetupLeanVelocity.LengthSqr();

	m_bIsAccelerating = velocity.Length2DSqr() > leanspd;

	m_vVelocity = g_LagCompensation.GetSmoothedVelocity(m_flLastClientSideAnimationUpdateTimeDelta * 2000.0f, velocity, m_vVelocity);

	m_vVelocityNormalized = VectorNormalizeReturn(m_vVelocity);

	float speed = std::fmin(m_vVelocity.Length(), 260.0f);
	m_flSpeed = speed;

	if (speed > 0.0f)
		m_vecLastAcceleratingVelocity = m_vVelocityNormalized;

	CBaseCombatWeapon *weapon = pBaseEntity->GetActiveCSWeapon();
	pActiveWeapon = weapon;

	float flMaxMovementSpeed = 260.0f;
	if (weapon)
		flMaxMovementSpeed = std::fmax(weapon->GetMaxSpeed3(), 0.001f);

	m_flSpeedNormalized = clamp(m_flSpeed / flMaxMovementSpeed, 0.0f, 1.0f);

	m_flRunningSpeed = m_flSpeed / (flMaxMovementSpeed * 0.520f);
	m_flDuckingSpeed = m_flSpeed / (flMaxMovementSpeed * 0.340f);

	if (m_flRunningSpeed < 1.0f)
	{
		if (m_flRunningSpeed < 0.5f)
		{
			float vel = m_flVelocityUnknown;
			float delta = m_flLastClientSideAnimationUpdateTimeDelta * 60.0f;
			float newvel;
			if ((80.0f - vel) <= delta)
			{
				if (-delta <= (80.0f - vel))
					newvel = 80.0f;
				else
					newvel = vel - delta;
			}
			else
			{
				newvel = vel + delta;
			}
			m_flVelocityUnknown = newvel;
		}
	}
	else
	{
		m_flVelocityUnknown = m_flSpeed;
	}

	bool bWasMovingLastUpdate = false;
	bool bJustStartedMovingLastUpdate = false;
	if (m_flSpeed <= 0.0f)
	{
		m_flTimeSinceStartedMoving = 0.0f;
		bWasMovingLastUpdate = m_flTimeSinceStoppedMoving <= 0.0f;
		m_flTimeSinceStoppedMoving += m_flLastClientSideAnimationUpdateTimeDelta;
	}
	else
	{
		m_flTimeSinceStoppedMoving = 0.0f;
		bJustStartedMovingLastUpdate = m_flTimeSinceStartedMoving <= 0.0f;
		m_flTimeSinceStartedMoving = m_flLastClientSideAnimationUpdateTimeDelta + m_flTimeSinceStartedMoving;
	}

	m_flCurrentFeetYaw = m_flGoalFeetYaw;
	m_flGoalFeetYaw = clamp(m_flGoalFeetYaw, -360.0f, 360.0f);

	float eye_feet_delta = AngleDiff(m_flEyeYaw, m_flGoalFeetYaw);

	float flRunningSpeed = clamp(m_flRunningSpeed, 0.0f, 1.0f);

	float flYawModifier = (((m_flGroundFraction * -0.3f) - 0.2f) * flRunningSpeed) + 1.0f;

	if (m_fDuckAmount > 0.0f)
	{
		float flDuckingSpeed = clamp(m_flDuckingSpeed, 0.0f, 1.0f);
		flYawModifier = flYawModifier + ((m_fDuckAmount * flDuckingSpeed) * (0.5f - flYawModifier));
	}

	float flMaxYawModifier = flYawModifier * m_flMaxYaw;
	float flMinYawModifier = flYawModifier * m_flMinYaw;

	if (eye_feet_delta <= flMaxYawModifier)
	{
		if (flMinYawModifier > eye_feet_delta)
			m_flGoalFeetYaw = fabs(flMinYawModifier) + m_flEyeYaw;
	}
	else
	{
		m_flGoalFeetYaw = m_flEyeYaw - fabs(flMaxYawModifier);
	}

	NormalizeAngle(m_flGoalFeetYaw);

	if (m_flSpeed > 0.1f || fabs(m_flAbsVelocityZ) > 100.0f)
	{
		m_flGoalFeetYaw = ApproachAngle(
			m_flEyeYaw,
			m_flGoalFeetYaw,
			((m_flGroundFraction * 20.0f) + 30.0f)
			* m_flLastClientSideAnimationUpdateTimeDelta);
	}
	else
	{
		m_flGoalFeetYaw = ApproachAngle(
			pBaseEntity->GetLowerBodyYaw(),
			m_flGoalFeetYaw,
			m_flLastClientSideAnimationUpdateTimeDelta * 100.0f);
	}

	C_AnimationLayer *layer3 = pBaseEntity->GetAnimOverlayDirect(3);
	if (layer3 && layer3->m_flWeight > 0.0f)
	{
		IncrementLayerCycle(3, false);
		LayerWeightAdvance(3);
	}

	if (m_flSpeed > 0.0f)
	{
		//turns speed into an angle
		float velAngle = (atan2(-m_vVelocity.y, -m_vVelocity.x) * 180.0f) * (1.0f / M_PI);

		if (velAngle < 0.0f)
			velAngle += 360.0f;

		m_flGoalMoveDirGoalFeetDelta = AngleNormalize(AngleDiff(velAngle, m_flGoalFeetYaw));
	}

	m_flFeetVelDirDelta = AngleNormalize(AngleDiff(m_flGoalMoveDirGoalFeetDelta, m_flCurrentMoveDirGoalFeetDelta));

	if (bJustStartedMovingLastUpdate && m_flFeetWeight <= 0.0f)
	{
		m_flCurrentMoveDirGoalFeetDelta = m_flGoalMoveDirGoalFeetDelta;

		C_AnimationLayer *layer = pBaseEntity->GetAnimOverlayDirect(6);
		int sequence = layer ? layer->_m_nSequence : 0;
		if (sequence != -1)
		{
			if (*(DWORD*)((DWORD)pBaseEntity->pSeqdesc(sequence) + 0xC4) > 0)
			{
				int tag = ANIMTAG_UNINITIALIZED;

				if (std::fabs(AngleDiff(m_flCurrentMoveDirGoalFeetDelta, 180.0f)) > 22.5f)
				{
					if (std::fabs(AngleDiff(m_flCurrentMoveDirGoalFeetDelta, 135.0f)) > 22.5f)
					{
						if (std::fabs(AngleDiff(m_flCurrentMoveDirGoalFeetDelta, 90.0f)) > 22.5f)
						{
							if (std::fabs(AngleDiff(m_flCurrentMoveDirGoalFeetDelta, 45.0f)) > 22.5f)
							{
								if (std::fabs(AngleDiff(m_flCurrentMoveDirGoalFeetDelta, 0.0f)) > 22.5f)
								{
									if (std::fabs(AngleDiff(m_flCurrentMoveDirGoalFeetDelta, -45.0f)) > 22.5f)
									{
										if (std::fabs(AngleDiff(m_flCurrentMoveDirGoalFeetDelta, -90.0f)) > 22.5f)
										{
											if (std::fabs(AngleDiff(m_flCurrentMoveDirGoalFeetDelta, -135.0f)) <= 22.5f)
												tag = ANIMTAG_STARTCYCLE_NW;
										}
										else
										{
											tag = ANIMTAG_STARTCYCLE_W;
										}
									}
									else
									{
										tag = ANIMTAG_STARTCYCLE_SW;
									}
								}
								else
								{
									tag = ANIMTAG_STARTCYCLE_S;
								}
							}
							else
							{
								tag = ANIMTAG_STARTCYCLE_SE;
							}
						}
						else
						{
							tag = ANIMTAG_STARTCYCLE_E;
						}
					}
					else
					{
						tag = ANIMTAG_STARTCYCLE_NE;
					}
				}
				else
				{
					tag = ANIMTAG_STARTCYCLE_N;
				}
				m_flFeetCycle = pBaseEntity->GetFirstSequenceAnimTag(sequence, tag);
			}
		}

		if (m_flDuckRate >= 1.0f && !m_bIsReset && std::fabs(m_flFeetVelDirDelta) > 45.0f)
		{
			if (m_bOnGround)
			{
				if (pBaseEntity->GetUnknownAnimationFloat() <= 0.0f)
					pBaseEntity->DoUnknownAnimationCode(StaticOffsets.GetOffsetValue(_UnknownAnimationFloat), 0.3f);
			}
		}
	}
	else
	{
		C_AnimationLayer *layer = pBaseEntity->GetAnimOverlayDirect(7);
		if (layer && layer->m_flWeight >= 1.0f)
		{
			m_flCurrentMoveDirGoalFeetDelta = m_flGoalMoveDirGoalFeetDelta;
		}
		else
		{
			if (m_flDuckRate >= 1.0f
				&& !m_bIsReset
				&& std::fabs(m_flFeetVelDirDelta) > 100.0f
				&& m_bOnGround
				&& pBaseEntity->GetUnknownAnimationFloat() <= 0.0f)
			{
				pBaseEntity->DoUnknownAnimationCode(StaticOffsets.GetOffsetValue(_UnknownAnimationFloat), 0.3f);
			}
			float flDuckSpeedClamp = clamp(m_flDuckingSpeed, 0.0f, 1.0f);
			float flRunningSpeedClamp = clamp(m_flRunningSpeed, 0.0f, 1.0f);
			float flLerped = ((flDuckSpeedClamp - flRunningSpeedClamp) * m_fDuckAmount) + flRunningSpeedClamp;
			float flBiasMove = /*powf(flLerped, 2.4739397f); //*/Bias(flLerped, 0.18f);
			m_flCurrentMoveDirGoalFeetDelta = AngleNormalize(((flBiasMove + 0.1f) * m_flFeetVelDirDelta) + m_flCurrentMoveDirGoalFeetDelta);
		}
	}

	m_arrPoseParameters[4].SetValue(pBaseEntity, m_flCurrentMoveDirGoalFeetDelta);

	float eye_goalfeet_delta = AngleDiff(m_flEyeYaw, m_flGoalFeetYaw);

	float new_body_yaw_pose = 0.0f; //not initialized?

	if (eye_goalfeet_delta < 0.0f || m_flMaxYaw == 0.0f)
	{
		if (m_flMinYaw != 0.0f)
			new_body_yaw_pose = (eye_goalfeet_delta / m_flMinYaw) * -58.0f;
	}
	else
	{
		new_body_yaw_pose = (eye_goalfeet_delta / m_flMaxYaw) * 58.0f;
	}

	m_arrPoseParameters[6].SetValue(pBaseEntity, new_body_yaw_pose);

	float eye_pitch_normalized = AngleNormalize(m_flPitch);
	float new_body_pitch_pose;

	if (eye_pitch_normalized <= 0.0f)
		new_body_pitch_pose = (eye_pitch_normalized / m_flMinPitch) * -90.0f;
	else
		new_body_pitch_pose = (eye_pitch_normalized / m_flMaxPitch) * 90.0f;

	m_arrPoseParameters[7].SetValue(pBaseEntity, new_body_pitch_pose);

	//Set pose parameter speed to m_flRunningSpeed
	m_arrPoseParameters[1].SetValue(pBaseEntity, m_flRunningSpeed);

	//Set pose parameter stand
	m_arrPoseParameters[9].SetValue(pBaseEntity, 1.0f - (m_flDuckRate * m_fDuckAmount));

	Interfaces::MDLCache->EndLock();
	END_PROFILING
}

void C_CSGOPlayerAnimState::SetupMovement()
{
	START_PROFILING
#if 0
#ifdef _DEBUG
	StaticOffsets.GetOffsetValueByType<void(__thiscall*)(C_CSGOPlayerAnimState*)>(_SetupMovement)(this);
	END_PROFILING
	return;
#endif
#endif
	Interfaces::MDLCache->BeginLock();

	float old_ground_fraction = m_flGroundFraction;
	if (old_ground_fraction > 0.0f && old_ground_fraction < 1.0f)
	{
		float twotickstime = m_flLastClientSideAnimationUpdateTimeDelta + m_flLastClientSideAnimationUpdateTimeDelta;
		if (m_bNotRunning)
			m_flGroundFraction = old_ground_fraction - twotickstime;
		else
			m_flGroundFraction = twotickstime + old_ground_fraction;

		m_flGroundFraction = clamp(m_flGroundFraction, 0.0f, 1.0f);
	}

	if (m_flSpeed > (260.0f * _CS_PLAYER_SPEED_WALK_MODIFIER) && m_bNotRunning)
	{
		m_bNotRunning = false;
		m_flGroundFraction = fmaxf(m_flGroundFraction, 0.01f);
	}
	else if (m_flSpeed < (260.0f * _CS_PLAYER_SPEED_WALK_MODIFIER) && !m_bNotRunning)
	{
		m_bNotRunning = true;
		m_flGroundFraction = fminf(m_flGroundFraction, 0.99f);
	}

	float duck_pose;

	if (m_iAnimsetVersion < 2)
	{
		m_arrPoseParameters[5].SetValue(pBaseEntity, m_flGroundFraction);
	}
	else
	{
		m_arrPoseParameters[17].SetValue(pBaseEntity, (1.0f - m_flGroundFraction) * (1.0f - m_fDuckAmount));
		m_arrPoseParameters[18].SetValue(pBaseEntity, (1.0f - m_fDuckAmount) * m_flGroundFraction);
		m_arrPoseParameters[19].SetValue(pBaseEntity, m_fDuckAmount);
	}

	char dest[64];
	//decrypts(0)
	sprintf_s(dest, XorStr("move_%s"), GetWeaponMoveAnimation());
	//encrypts(0)

	int seq = pBaseEntity->LookupSequence(dest);
	if (seq == -1)
	{
		//decrypts(0)
		seq = pBaseEntity->LookupSequence(XorStr("move"));
		//encrypts(0)
	}

	if (pBaseEntity->GetMoveState() != m_iMoveState)
		m_flMovePlaybackRate += 10.0f;

	m_iMoveState = pBaseEntity->GetMoveState();

	float movement_time_delta = m_flLastClientSideAnimationUpdateTimeDelta * 40.0f;

	if (-m_flMovePlaybackRate <= movement_time_delta)
	{
		if (-movement_time_delta <= -m_flMovePlaybackRate)
			m_flMovePlaybackRate = 0.0f;
		else
			m_flMovePlaybackRate = m_flMovePlaybackRate - movement_time_delta;
	}
	else
	{
		m_flMovePlaybackRate = m_flMovePlaybackRate + movement_time_delta;
	}

	m_flMovePlaybackRate = clamp(m_flMovePlaybackRate, 0.0f, 100.0f);

	float duckspeed_clamped = clamp(m_flDuckingSpeed, 0.0f, 1.0f);
	float runspeed_clamped = clamp(m_flRunningSpeed, 0.0f, 1.0f);

	float speed_weight = ((duckspeed_clamped - runspeed_clamped) * m_fDuckAmount) + runspeed_clamped;

	if (speed_weight < m_flFeetWeight)
	{
		float v34 = clamp(m_flMovePlaybackRate * 0.01f, 0.0f, 1.0f);
		float feetweight_elapsed = ((v34 * 18.0f) + 2.0f) * m_flLastClientSideAnimationUpdateTimeDelta;
		if (speed_weight - m_flFeetWeight <= feetweight_elapsed)
			m_flFeetWeight = -feetweight_elapsed <= (speed_weight - m_flFeetWeight) ? speed_weight : m_flFeetWeight - feetweight_elapsed;
		else
			m_flFeetWeight = feetweight_elapsed + m_flFeetWeight;
	}
	else
	{
		m_flFeetWeight = speed_weight;
	}

	float yaw = AngleNormalize((m_flCurrentMoveDirGoalFeetDelta + m_flGoalFeetYaw) + 180.0f);
	QAngle angle = { 0.0f, yaw, 0.0f };
	Vector vecDir;
	AngleVectors(angle, &vecDir);

	float movement_side = DotProduct(m_vecLastAcceleratingVelocity, vecDir);
	if (movement_side < 0.0f)
		movement_side = -movement_side;

	float newfeetweight = Bias(movement_side, 0.2f) * m_flFeetWeight;

	m_flFeetWeight = newfeetweight; //TODO: find out how to resolve based off this

	float newfeetweight2 = newfeetweight * m_flDuckRate;

	float layer5_weight = GetLayerWeight(5);

	float new_weight = 0.55f;
	if (1.0f - layer5_weight > 0.55f)
		new_weight = 1.0f - layer5_weight;

	float new_feet_layer_weight = new_weight * newfeetweight2;
	float feet_cycle_rate = 0.0f;

	if (m_flSpeed > 0.00f)
	{
		float seqcyclerate = pBaseEntity->GetSequenceCycleRate(seq);

		float seqmovedist = pBaseEntity->GetSequenceMoveDist(pBaseEntity->GetModelPtr(), seq);
		seqmovedist *= 1.0f / (1.0f / seqcyclerate);
		if (seqmovedist <= 0.001f)
			seqmovedist = 0.001f;

		float speed_multiplier = m_flSpeed / seqmovedist;
		feet_cycle_rate = (1.0f - (m_flGroundFraction * 0.15f)) * (speed_multiplier * seqcyclerate);
	}

	float feetcycle_playback_rate = (m_flLastClientSideAnimationUpdateTimeDelta * feet_cycle_rate);
	SetFeetCycle(feetcycle_playback_rate + m_flFeetCycle); //TODO: find out how to resolve based off this

	UpdateAnimLayer(feetcycle_playback_rate, 6, seq, clamp(new_feet_layer_weight, 0.0f, 1.0f), m_flFeetCycle); //TODO: find out how to resolve based off this

	if (pBaseEntity->IsStrafing())
	{
		if (!m_bStrafing)
		{
			m_flTotalStrafeTime = 0.0f;
			if (!m_bIsReset && m_bOnGround && pBaseEntity->GetUnknownSetupMovementFloat() <= 0.0f)
				pBaseEntity->DoUnknownAnimationCode(StaticOffsets.GetOffsetValue(_UnknownSetupMovementFloat), 0.15f);
		}

		float strafe_weight_time_delta = m_flLastClientSideAnimationUpdateTimeDelta * 20.0f;
		m_bStrafing = true;

		//if this is fucked, redo again
		if (1.0f - m_flStrafeWeight <= strafe_weight_time_delta)
			m_flStrafeWeight = -strafe_weight_time_delta <= (1.0f - m_flStrafeWeight) ? 1.0f : m_flStrafeWeight - strafe_weight_time_delta;
		else
			m_flStrafeWeight = m_flStrafeWeight + strafe_weight_time_delta;

		float strafe_cycle_time_delta = m_flLastClientSideAnimationUpdateTimeDelta * 10.0f;
		if (-m_flStrafeCycle <= strafe_cycle_time_delta)
			m_flStrafeCycle = -strafe_cycle_time_delta <= -m_flStrafeCycle ? 0.0f : m_flStrafeCycle - strafe_cycle_time_delta;
		else
			m_flStrafeCycle = m_flStrafeCycle + strafe_cycle_time_delta;

		float CurrentMoveDirGoalFeetDelta = AngleNormalize(m_flCurrentMoveDirGoalFeetDelta);

		m_arrPoseParameters[13].SetValue(pBaseEntity, CurrentMoveDirGoalFeetDelta);
	}
	else
	{
		if (m_arrPoseParameters[13].m_bInitialized)
		{
			if (m_flStrafeWeight > 0.0f)
			{
				m_flTotalStrafeTime += m_flLastClientSideAnimationUpdateTimeDelta;
				if (m_flTotalStrafeTime > 0.08f)
				{
					float newtimedelta3 = m_flLastClientSideAnimationUpdateTimeDelta * 5.0f;
					if (-m_flStrafeWeight <= newtimedelta3)
						m_flStrafeWeight = -newtimedelta3 <= -m_flStrafeWeight ? 0.0f : m_flStrafeWeight - newtimedelta3;
					else
						m_flStrafeWeight = m_flStrafeWeight + newtimedelta3;
				}

				//decrypts(0)
				m_iStrafeSequence = pBaseEntity->LookupSequence(XorStr("strafe"));
				//encrypts(0)

				float seqcyclerate2 = pBaseEntity->GetSequenceCycleRate(m_iStrafeSequence);

				m_flStrafeCycle += (m_flLastClientSideAnimationUpdateTimeDelta * seqcyclerate2);
				m_flStrafeCycle = clamp(m_flStrafeCycle, 0.0f, 1.0f);
			}
		}
	}

	if (0.0f >= m_flStrafeWeight)
		m_bStrafing = false;

	bool old_onground = m_bOnGround;
	bool new_onground = pBaseEntity->GetFlags() & FL_ONGROUND || pBaseEntity->GetWaterLevel() >= WL_Feet;
	m_bOnGround = new_onground;

	bool just_landed;
	if (!m_bIsReset && old_onground != new_onground && new_onground)
		just_landed = true;
	else
		just_landed = false;

	m_bJust_Landed = just_landed;

	bool just_left_ground = old_onground != new_onground && !new_onground;

	m_bJust_LeftGround = just_left_ground;

	if (just_left_ground)
		m_flStartJumpZOrigin = m_vOrigin.z;

	if (just_landed)
	{
		float zdelta = fabsf(m_flStartJumpZOrigin - m_vOrigin.z);
		zdelta = (zdelta - 12.0f) * 0.017f ;
		zdelta = clamp(zdelta, 0.0f, 1.0f);

		float v91 = Bias(zdelta, 0.4f);
		float v94 = clamp(Bias(m_flTotalTimeInAir, 0.3f), 0.1f, 1.0f);

		m_flHitGroundWeight = v94;

		m_flHitGroundCycle = v94 <= v91 ? v91 : v94;
	}
	else
	{
		float twotickstime = m_flLastClientSideAnimationUpdateTimeDelta + m_flLastClientSideAnimationUpdateTimeDelta;
		if (-m_flHitGroundCycle <= twotickstime)
			m_flHitGroundCycle = -twotickstime <= -m_flHitGroundCycle ? 0.0f : m_flHitGroundCycle - twotickstime;
		else
			m_flHitGroundCycle = m_flHitGroundCycle + twotickstime;
	}

	float flOnGround = (float)(new_onground != 0);
	float newduckrate = ((m_fDuckAmount + 1.0f) * 8.0f) * m_flLastClientSideAnimationUpdateTimeDelta;

	if ((flOnGround - m_flDuckRate) <= newduckrate)
		newduckrate = -newduckrate <= flOnGround - m_flDuckRate ? flOnGround : m_flDuckRate - newduckrate;
	else
		newduckrate = m_flDuckRate + newduckrate;

	m_flDuckRate = clamp(newduckrate, 0.0f, 1.0f);

	float new_strafe_weight = ((1.0f - m_fDuckAmount) * m_flStrafeWeight) * m_flDuckRate;
	m_flStrafeWeight = clamp(new_strafe_weight, 0.0f, 1.0f);
	int strafe_sequence = m_iStrafeSequence;
	if (strafe_sequence != -1)
		UpdateAnimLayer(0.0f, 7, strafe_sequence, m_flStrafeWeight, m_flStrafeCycle);

	bool old_onladder = m_bOnLadder;
	bool new_onladder = !m_bOnGround && pBaseEntity->GetMoveType() == MOVETYPE_LADDER;
	m_bOnLadder = new_onladder;

	//bool not_onladder = !old_onladder || !new_onladder;
	bool not_onladder;
	if (!old_onladder || (not_onladder = true, new_onladder))
		not_onladder = false;

	if (m_flLadderCycle <= 0.0f && !new_onladder)
	{
		m_flLadderWeight = 0.0f;
	}
	else
	{
		float laddertimedelta = m_flLastClientSideAnimationUpdateTimeDelta * 10.0f;
		float v113;
		if (fabsf(m_flAbsVelocityZ) <= 100.0f)
		{
			if (-m_flLadderWeight <= laddertimedelta)
				v113 = -laddertimedelta <= -m_flLadderWeight ? 0.0f : m_flLadderWeight - laddertimedelta;
			else
				v113 = m_flLadderWeight + laddertimedelta;
		}
		else if (1.0f - m_flLadderWeight <= laddertimedelta)
		{
			v113 = -laddertimedelta <= 1.0f - m_flLadderWeight ? 1.0f : m_flLadderWeight - laddertimedelta;
		}
		else
		{
			v113 = m_flLadderWeight + laddertimedelta;
		}

		m_flLadderWeight = clamp(v113, 0.0f, 1.0f);

		float v116;
		if (new_onladder)
		{
			float timedelta4 = m_flLastClientSideAnimationUpdateTimeDelta * 5.0f;
			if (1.0f - m_flLadderCycle <= timedelta4)
				v116 = -timedelta4 <= 1.0f - m_flLadderCycle ? 1.0f : m_flLadderCycle - timedelta4;
			else
				v116 = m_flLadderCycle + timedelta4;
		}
		else if (-m_flLadderCycle <= laddertimedelta)
		{
			v116 = -laddertimedelta <= -m_flLadderCycle ? 0.0f : m_flLadderCycle - laddertimedelta;
		}
		else
		{
			v116 = m_flLadderCycle + laddertimedelta;
		}
		m_flLadderCycle = clamp(v116, 0.0f, 1.0f);

		Vector laddernormal = pBaseEntity->GetVecLadderNormal();
		QAngle ladderAngles;
		VectorAngles(laddernormal, ladderAngles);

		float ladderGoalFeetYawDelta = AngleDiff(ladderAngles.y, m_flGoalFeetYaw);

		m_arrPoseParameters[3].SetValue(pBaseEntity, ladderGoalFeetYawDelta);

		float layer5_cycle = GetLayerCycle(5);

		float unk = m_flLadderWeight * 0.006f;
		float newpose2 = ((m_vOrigin.z - m_vLastOrigin.z) * (0.01f - unk)) + layer5_cycle;
		m_arrPoseParameters[2].SetValue(pBaseEntity, m_flLadderWeight);

		if (GetLayerActivity(5) == 987)
			SetLayerWeight(5, m_flLadderCycle);

		SetLayerCycle(5, newpose2);

		if (m_bOnLadder)
		{
			float layer4_idealweight = 1.0f - m_flLadderCycle;

			if (GetLayerWeight(4) > layer4_idealweight)
				SetLayerWeight(4, layer4_idealweight);
		}
	}
	
	if (!m_bOnGround)
	{
		if (!m_bOnLadder)
		{
			//PLAYER IS IN THE AIR

			m_bInHitGroundAnimation = false;
			if (m_bJust_LeftGround || not_onladder)
				m_flTotalTimeInAir = 0.0f;

			m_flTotalTimeInAir += m_flLastClientSideAnimationUpdateTimeDelta;
			IncrementLayerCycle(4, false);

			float layer4_weight = GetLayerWeight(4);
			float layer4_idealweight = GetLayerIdealWeightFromSeqCycle(4);

			if (layer4_idealweight > layer4_weight)
				SetLayerWeight(4, layer4_idealweight);

			C_AnimationLayer *layer5 = pBaseEntity->GetAnimOverlay(5);
			if (layer5)
			{
				if (layer5->m_flWeight > 0.0f)
				{
					float v175 = (m_flTotalTimeInAir - 0.2f) * -5.0f;
					v175 = clamp(v175, 0.0f, 1.0f);
					float newlayer5_weight = ((3.0f - (v175 + v175)) * (v175 * v175)) * layer5->m_flWeight;
					SetLayerWeight(5, newlayer5_weight);
				}
			}

			float v203 = (m_flTotalTimeInAir - 0.72f) * 1.25f;
			v203 = clamp(v203, 0.0f, 1.0f);
			float newpose10 = (3.0f - (v203 + v203)) * (v203 * v203);
			newpose10 = clamp(newpose10, 0.0f, 1.0f);
			m_arrPoseParameters[10].SetValue(pBaseEntity, newpose10);
			Interfaces::MDLCache->EndLock();
			END_PROFILING
			return;
		}
		Interfaces::MDLCache->EndLock();
		END_PROFILING
		return;
	}

	if (!m_bInHitGroundAnimation)
	{
		if (m_bJust_Landed || not_onladder)
		{
			//Start the hit ground animation , went here when fucked
			SetLayerCycle(5, 0.0f);
			m_bInHitGroundAnimation = true;
		}
	}

	if (!m_bInHitGroundAnimation || GetLayerActivity(5) == 987) //ACT_CSGO_CLIMB_LADDER
	{
		Interfaces::MDLCache->EndLock();
		END_PROFILING
		return;
	}
	//went here when fucked
	IncrementLayerCycle(5, false);
	IncrementLayerCycle(4, false);
	m_arrPoseParameters[10].SetValue(pBaseEntity, 0.0f);

	C_AnimationLayer* layer5 = pBaseEntity->GetAnimOverlay(5);
	if (layer5)
	{
		float layer5_nextcycle = (layer5->_m_flPlaybackRate * m_flLastClientSideAnimationUpdateTimeDelta) + layer5->_m_flCycle;

		//check to see if the hit ground animation is finished
		if (layer5_nextcycle >= 1.0f)
		{
			//FINISHED HITTING GROUND ANIMATION
			m_bInHitGroundAnimation = false;
			SetLayerWeight(5, 0.0f);
			SetLayerWeight(4, 0.0f);
			m_flHitGroundWeight = 1.0f;
			Interfaces::MDLCache->EndLock();
			END_PROFILING
			return;
		}
	}

	//STILL IN HITTING GROUND ANIMATION

	float layer5_idealweight = GetLayerIdealWeightFromSeqCycle(5) * m_flHitGroundWeight;
	float weight_mult = 0.2f;
	float v168 = 1.0f - m_fDuckAmount;
	if (v168 >= 0.2f)
		weight_mult = fminf(v168, 1.0f);

	SetLayerWeight(5, weight_mult * layer5_idealweight);

	float layer4_weight = GetLayerWeight(4);
	if (layer4_weight <= 0.0f)
	{
		Interfaces::MDLCache->EndLock();
		END_PROFILING
		return;
	}

	float timedelta5 = m_flLastClientSideAnimationUpdateTimeDelta * 10.0f;

	C_AnimationLayer *layer4 = GetAnimOverlay(4);
	if (layer4)
	{
		if (-layer4_weight <= timedelta5)
		{
			if (-timedelta5 <= -layer4_weight)
				SetLayerWeight(4, 0.0f);
			else
				SetLayerWeight(4, layer4_weight - timedelta5);
		}
		else
		{
			SetLayerWeight(4, timedelta5 + layer4_weight);
		}
	}

	Interfaces::MDLCache->EndLock();
	END_PROFILING
}

void C_CSGOPlayerAnimState::SetupFlinch()
{
	START_PROFILING
	IncrementLayerCycle(10, false);
	END_PROFILING
}

void C_CSGOPlayerAnimState::SetupAliveloop()
{
	START_PROFILING
	IncrementLayerCycleGeneric(11);
	END_PROFILING
}

void C_CSGOPlayerAnimState::SetupWholeBodyAction()
{
	START_PROFILING
	C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(8);
	if (pLayer && pLayer->m_flWeight > 0.0f)
	{
		IncrementLayerCycle(8, false);
		LayerWeightAdvance(8);
	}
	END_PROFILING
}

void C_CSGOPlayerAnimState::UpdateAnimLayer(float playbackrate, int layer, int sequence, float weight, float cycle)
{
	if (sequence >= 2)
	{
		Interfaces::MDLCache->BeginLock();
		C_AnimationLayer *pLayer = pBaseEntity->GetAnimOverlay(layer);
		if (pLayer)
		{
			pLayer->SetSequence(sequence);
			pLayer->_m_flPlaybackRate = playbackrate;
			pLayer->SetCycle(clamp(cycle, 0.0f, 1.0f));
			pLayer->SetWeight(clamp(weight, 0.0f, 1.0f));
			UpdateLayerOrderPreset(weight, layer, sequence);
		}
		Interfaces::MDLCache->EndLock();
	}
}

void C_CSGOPlayerAnimState::UpdateLayerOrderPreset(float weight, int layer, int sequence)
{
	auto func = StaticOffsets.GetOffsetValueByType<void(__thiscall*)(C_CSGOPlayerAnimState*, int, int)>(_UpdateLayerOrderPreset);
	__asm movss xmm0, weight;
	func(this, layer, sequence);
}

float C_CSGOPlayerAnimState::GetLayerIdealWeightFromSeqCycle(int layer)
{
	//auto func = StaticOffsets.GetOffsetValueByType<void(__thiscall*)(C_CSGOPlayerAnimState*, int)>(_GetLayerIdealWeightFromSeqCycle);
	//float retval;
	//func(this, layer);
	//__asm movss retval, xmm0
	//return retval;

	Interfaces::MDLCache->BeginLock();
	C_AnimationLayer *overlay = pBaseEntity->GetAnimOverlay(layer);
	if (!overlay)
	{
		Interfaces::MDLCache->EndLock();
		return 0.0f;
	}

	int sequence = overlay->_m_nSequence;
	CStudioHdr *modelptr = pBaseEntity->GetModelPtr();
	mstudioseqdesc_t *seqdesc;
	//NOTE TO VALVE: you don't check for valid pointer here!
	if (modelptr->m_pVModel)
		seqdesc = opSeqdesc((studiohdr_t*)modelptr, sequence);
	else
		seqdesc = modelptr->_m_pStudioHdr->pLocalSeqdesc(sequence);

	float cycle = overlay->_m_flCycle;
	if (cycle >= 0.99f)
		cycle = 1.0f;

	float fadeintime = seqdesc->fadeintime;
	float fadeouttime = seqdesc->fadeouttime;
	float weight = 1.0f;
	float v15;

	if (fadeintime <= 0.0f || fadeintime <= cycle)
	{
		if (fadeouttime >= 1.0f || cycle <= fadeouttime)
		{
			weight = fminf(weight, 1.0f);
			Interfaces::MDLCache->EndLock();
			return weight;
		}
		v15 = (cycle - 1.0f) / (fadeouttime - 1.0f);
		v15 = clamp(v15, 0.0f, 1.0f);
	}
	else
	{
		v15 = clamp(cycle / fadeintime, 0.0f, 1.0f);
	}
	weight = (3.0f - (v15 + v15)) * (v15 * v15);
	if (weight < 0.0015f)
		weight = 0.0f;
	else
		weight = clamp(weight, 0.0f, 1.0f);

	Interfaces::MDLCache->EndLock();
	return weight;
}

void C_CSGOPlayerAnimState::SetupFlashedReaction()
{
	START_PROFILING
	C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(9);
	if (pLayer && pLayer->m_flWeight > 0.0f && pLayer->m_flWeightDeltaRate < 0.0f)
		LayerWeightAdvance(9);
	END_PROFILING
}

void C_CSGOPlayerAnimState::LayerWeightAdvance(int layer)
{
	C_AnimationLayer* pLayer = pBaseEntity->GetAnimOverlay(layer);
	if (!layer || fabs(pLayer->m_flWeightDeltaRate) <= 0.0f)
		return;

	float newweight = (pLayer->m_flWeightDeltaRate * m_flLastClientSideAnimationUpdateTimeDelta) + pLayer->m_flWeight;
	newweight		= clamp(newweight, 0.0f, 1.0f);
	pLayer->SetWeight(newweight);
}

C_AnimationLayer* C_CSGOPlayerAnimState::GetAnimOverlay(int layer)
{
	CUtlVectorSimple* m_AnimOverlay = pBaseEntity->GetAnimOverlayStruct();
	int numoverlays					= m_AnimOverlay->count;
	int maxindex					= numoverlays - 1;
	int index = layer;
	if (maxindex >= 0)
	{
		if (layer > maxindex)
			index = numoverlays - 1;
	}
	else
	{
		index = 0;
	}

	if (numoverlays)
		return (C_AnimationLayer*)m_AnimOverlay->Retrieve(index, sizeof(C_AnimationLayer));

	return nullptr;
}

int C_CSGOPlayerAnimState::GetLayerActivity(int layer)
{
	C_AnimationLayer* pLayer = GetAnimOverlay(layer);
	if (!pLayer)
		return -1;

	//This is not the same as the game code, but cba to rebuild this function properly right now
	return GetSequenceActivity(pBaseEntity, pLayer->_m_nSequence);
}