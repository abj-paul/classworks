from fastapi import FastAPI
from BattleRecordService import *
from BattleRecordModel import BattleRecord

app = FastAPI()

@app.on_event("startup")
async def connect_to_database():
    await connect_db()
    await create_battle_table()

@app.get("/")
async def root_get_procedure():
    return {"status":"FastAPI server has started running!"}

@app.post("/api/save_battle_record")
async def save_battle_record(battleRecord : BattleRecord):
    await insert_battle_record(battleRecord=battleRecord)
    return {"status": "Battle has been saved."}

@app.get("/api/get_battle_records", response_model=list[BattleRecord])
async def get_battle_records():
    records = await fetch_records()
    print(records)
    return records 

@app.get("/api/get_battle_records/{battle_id}", response_model=BattleRecord)
async def get_single_record(battle_id: int):
    record = await fetch_single_record(battle_id=battle_id)
    return record[0]

@app.put("/api/update_battle_records/drops")
async def update_drops(battle_id: int, new_drops: str):
    await update_battle_record_drop(battle_id, new_drops)
    return {"status": "Successfully updated drops for battle "+str(battle_id)} 