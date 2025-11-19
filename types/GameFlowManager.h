enum GameFlowState {
	GAMEFLOW_STATE_NONE = 0,
	GAMEFLOW_STATE_LOADING_FRONTEND = 1,
	GAMEFLOW_STATE_UNLOADING_FRONTEND = 2,
	GAMEFLOW_STATE_IN_FRONTEND = 3,
	GAMEFLOW_STATE_LOADING_REGION = 4,
	GAMEFLOW_STATE_LOADING_TRACK = 5,
	GAMEFLOW_STATE_RACING = 6,
	GAMEFLOW_STATE_UNLOADING_TRACK = 7,
	GAMEFLOW_STATE_UNLOADING_REGION = 8,
	GAMEFLOW_STATE_EXIT_DEMO_DISC = 9,
};

class GameFlowManager {
public:
	void* pSingleFunction;
	uint32_t SingleFunctionParam;
	const char* pSingleFunctionName;
	void* pLoopingFunction;
	const char* pLoopingFunctionName;
	bool WaitingForCallback;
	const char* pCallbackName;
	uint32_t CallbackPhase;
	uint32_t CurrentGameFlowState;
};
static_assert(sizeof(GameFlowManager) == 0x24);

auto& TheGameFlowManager = *(GameFlowManager*)0x925E70;