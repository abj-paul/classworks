from fastapi import FastAPI

from Item import Item
from database import *

app = FastAPI()
@app.on_event("startup")
async def connect_with_database():
    await connect_db()

@app.get("/item/")
def getItem():
    #return Item(2, "Shampoo").json
    return {"name": "Abhijit Paul"}

@app.post("/item/")
async def postItem():
    await insert()
