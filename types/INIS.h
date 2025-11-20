class CAnimChooser {
public:
	enum eType {
		Intro = 0,
		Arrest = 1,
		Ending = 2,
		World = 3,
		Moment = 4,
		MaxTypes = 5,
	};
};

class CAnimScene;
class ICEScene;

class INIS : public UCOM::IUnknown {
public:
	static inline auto& mInstance = *(INIS**)0x9885C8;

	virtual void AddCar(UCrc32, IVehicle*) = 0;
	virtual IVehicle* GetCar(UCrc32) = 0;
	virtual void StartLocation(const UMath::Vector3*, float) = 0;
	virtual void StartLocationInRenderCoords(const bVector3*, uint16_t) = 0;
	virtual const UMath::Vector3* GetStartLocation() = 0;
	virtual const UMath::Vector3* GetStartCameraLocation() = 0;
	virtual void SetPreMovie(const char*) = 0;
	virtual void SetPostMovie(const char*) = 0;
	virtual int GetType() = 0;
	virtual void Load(CAnimChooser::eType, const char*, int, bool) = 0;
	virtual void SkipOverNIS() = 0;
	virtual void Pause() = 0;
	virtual void UnPause() = 0;
	virtual bool IsLoaded() = 0;
	virtual bool IsPlaying() = 0;
	virtual bool InMovie() = 0;
	virtual void ServiceLoads() = 0;
	virtual ICEScene* GetScene() = 0;
	virtual CAnimScene* GetAnimScene() = 0;
	virtual void Release() = 0;
	virtual void StartEvents() = 0;
	virtual void FireEventTag(const char*) = 0;
	virtual void ResetEvents(float) = 0;
	virtual void StartPlayingNow() = 0;
	virtual bool IsWorldMomement() = 0;
};