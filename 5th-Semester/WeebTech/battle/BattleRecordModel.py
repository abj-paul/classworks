from pydantic import BaseModel

class BattleRecord(BaseModel):
    battle_name: str = "Battle of Ice & Fire"
    battle_location: str = "West Vermillion Peak"
    participant_name: str = "Daoist Violet Rhyme"
    opposition_name: str = "Fairy Ice Empress"
    battle_record: str = "The first and ice can not co-exist hence the battle in the peak for the supremacy of element. Fairy Ice Empress turned the battlefield into a domain of ice while daoist violet rhyme turned the sky into a meteor shower. They fought for 5 nights and 7 days and the battle ended in a draw."
    winner: str = "both"
    drops: str = "Minor Fusion of Fire & Ice"