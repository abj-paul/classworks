from databases import Database
import asyncio
from BattleRecordModel import BattleRecord


DATABASE_NAME = "quest_database"

database = Database("mysql+aiomysql://root:@localhost:3306/"+DATABASE_NAME)

async def connect_db():
    await database.connect()
    print("FastAPI has successfully connected to database "+DATABASE_NAME )

async def create_battle_table():
    query = '''
        CREATE TABLE if not exists battle(
            battle_id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
            battle_name varchar(100),
            battle_location varchar(100),
            participant_name varchar(50),
            opposition_name varchar(50),
            battle_record varchar(500),
            winner varchar(50),
            drops varchar(100) 
        )
    '''

    await database.execute(query=query)
    print("Battle table has been created!")

async def insert_battle_record(battleRecord: BattleRecord):
    query = "insert into battle(battle_name, battle_location, participant_name, opposition_name, battle_record, winner, drops) values (:battle_name,:battle_location,:participant_name,:opposition_name,:battle_record,:winner,:drops) ;"
    values = {
            "battle_name": battleRecord.battle_name,
            "battle_location": battleRecord.battle_location,
            "participant_name": battleRecord.participant_name,
            "opposition_name": battleRecord.opposition_name,
            "battle_record": battleRecord.battle_record,
            "winner": battleRecord.winner,
            "drops": battleRecord.drops
        }
    await database.execute(query=query, values=values)
    print("Records for the battle of "+battleRecord.battle_location+" has been saved!")

async def fetch_records():
    query = "SELECT * FROM battle;"
    result = await database.fetch_all(query=query)
    return result

async def fetch_single_record(battle_id:int):
    query = "SELECT * FROM battle WHERE battle_id=:battle_id ;"
    values = {"battle_id":battle_id}
    record = await database.fetch_all(query=query, values=values)
    return record

async def update_battle_record_drop(battle_id: int, drops: str):
    query = "UPDATE battle SET drops=:drops where battle_id=:battle_id"
    values = {"drops":drops, "battle_id":battle_id}

    await database.execute(query, values)