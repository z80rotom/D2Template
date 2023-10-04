struct D2UnitStrc;

struct D2CorpseStrc
{
	uint32_t unk0x00;						//0x00
	uint32_t dwUnitId;						//0x04
	uint32_t unk0x08;						//0x08
	D2CorpseStrc* pNextCorpse;				//0x0C
};

struct D2InventoryNodeStrc
{
	int32_t nItemId;						//0x00
	D2InventoryNodeStrc* pNext;				//0x04
};

struct D2InventoryGridStrc
{
	D2UnitStrc* pItem;						//0x00
	D2UnitStrc* pLastItem;					//0x04
	uint8_t nGridWidth;						//0x08
	uint8_t nGridHeight;					//0x09
	uint16_t pad0x0A;						//0x0A
	D2UnitStrc** ppItems;					//0x0C
};

struct D2InventoryStrc
{
	uint32_t dwSignature;					//0x00
	void* pMemPool;							//0x04
	D2UnitStrc* pOwner;						//0x08
	D2UnitStrc* pFirstItem;					//0x0C
	D2UnitStrc* pLastItem;					//0x10
	D2InventoryGridStrc* pGrids;			//0x14
	int32_t nGridCount;						//0x18
	D2UnitGUID dwLeftItemGUID;				//0x1C
	D2UnitStrc* pCursorItem;				//0x20
	D2UnitGUID dwOwnerGuid;					//0x24
	uint32_t dwItemCount;					//0x28
	D2InventoryNodeStrc* pFirstNode;		//0x2C
	D2InventoryNodeStrc* pLastNode;			//0x30
	D2CorpseStrc* pFirstCorpse;				//0x34
	D2CorpseStrc* pLastCorpse;				//0x38
	int32_t nCorpseCount;					//0x3C
};
