from databases import Database
import asyncio

database = Database("mysql+aiomysql://root:@localhost:3306/itemdb")

# Establish the connection pool
async def connect_db():
    await database.connect()

async def insert():
    query = "insert into item(name, price) values(:name, :price)"
    values = {"name":"Shampoo", "price":200}

    await database.execute(query=query, values=values)



