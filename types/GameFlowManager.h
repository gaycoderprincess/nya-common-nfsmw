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