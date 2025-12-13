class eSolidPlatInfo;
class eSolidPlatInterface {
public:
	eSolidPlatInfo* PlatInfo;
};

class eTextureEntry;
class eLightMaterialEntry;
class ePositionMarker;
class eNormalSmoother;
class eDamageVertex;
class eConnectivityData;
class eSolid : public eSolidPlatInterface, bTList<eSolid> {
public:
	unsigned char Version;
	unsigned char EndianSwapped;
	unsigned short Flags;
	unsigned int NameHash;
	short NumPolys;
	short NumVerts;
	char NumBones;
	char NumTextureTableEntries;
	char NumLightMaterials;
	char NumPositionMarkerTableEntries;
	int ReferencedFrameCounter;
	float AABBMinX;
	float AABBMinY;
	float AABBMinZ;
	eTextureEntry* pTextureTable;
	float AABBMaxX;
	float AABBMaxY;
	float AABBMaxZ;
	eLightMaterialEntry* LightMaterialTable;
	bMatrix4 PivotMatrix;
	ePositionMarker* PositionMarkerTable;
	eNormalSmoother* NormalSmoother;
	bTList<eModel> ModelList;
	eDamageVertex* DamageVertexTable;
	eConnectivityData* ConnectivityData;
	float Volume;
	float Density;
	char Name[64];
};
static_assert(sizeof(eSolid) == 0xE0);

class eReplacementTextureTable {
public:
	unsigned int hOldNameHash;
	unsigned int hNewNameHash;
	TextureInfo* pTextureInfo;
};
static_assert(sizeof(eReplacementTextureTable) == 0xC);

class eModel : public bTList<eModel> {
public:
	unsigned int NameHash;
	eSolid* Solid;
	eReplacementTextureTable* pReplacementTextureTable;
	int NumReplacementTextures;
};
static_assert(sizeof(eModel) == 0x18);