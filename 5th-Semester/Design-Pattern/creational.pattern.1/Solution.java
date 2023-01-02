import java.util.ArrayList;

interface Ingredient{}
class Direction{
    public static int East = 1;
    public static int West = 2;
    public static int North = 3;
    public static int South = 4;
}




class Maze {
    ArrayList<Room> mazeRooms = new ArrayList<>();
    // Maze(){
    //     this.mazeRooms = new ArrayList<Room>();
    // }
    public void addRoom(Room room){
        mazeRooms.add(room);
        System.out.println("openig..");
    }

    public void printLayout(){
        System.out.println("Total Rooms = "+ mazeRooms.size());
        for(Room room: mazeRooms){
            System.out.println(room.toString());
        }
    }
}



class Room {
    int roomNumber;
    Room(int roomNumber){
        this.roomNumber = roomNumber;
    }
    public void setSide(int direction, Ingredient ingredient) {
        // Do nothing
    }
    @Override
    public String toString() {
        return "Room number "+roomNumber;
    }
}
class RoomWithABomb extends Room {
    RoomWithABomb(int n){
        super(n);
    }
}
class EnchantedRoom extends Room {
    private int spell;
    public EnchantedRoom(int n, int spell){
        super(n);
        this.spell = spell;
    }
}







class Door implements Ingredient{
    private Room room1, room2;
    Door(Room room1, Room room2){
        this.room1 = room1;
        this.room2 = room2;
    }
}

class DoorNeedingSpell extends Door {
    DoorNeedingSpell(Room r1, Room r2){
        super(r1, r2);
        // Do some more stuffs now
    }
}






class Wall implements Ingredient{}
class BombedWall extends Wall {}



abstract class MazeGame {
    public Maze createMaze(){
        Maze aMaze = makeMaze();

        Room r1 = makeRoom(1);
        Room r2 = makeRoom(2);

        Door theDoor = makeDoor(r1, r2);

        aMaze.addRoom(r1);
        aMaze.addRoom(r2);

        r1.setSide(Direction.North, makeWall());
        r1.setSide(Direction.East, theDoor);
        r1.setSide(Direction.South, makeWall());
        r1.setSide(Direction.West, makeWall());

        r2.setSide(Direction.North, makeWall());
        r2.setSide(Direction.East, makeWall());
        r2.setSide(Direction.South, makeWall());
        r2.setSide(Direction.West, theDoor);

        return aMaze;
    }

    public Maze makeMaze(){
        return new Maze();
    }
    public Room makeRoom(int n){
        return new Room(n);
    }
    public Wall makeWall(){
        return new Wall();
    }
    public Door makeDoor(Room r1, Room r2){
        return new Door(r1, r2);
    }

}

class BombedMazeGame extends MazeGame {
    public BombedMazeGame(){}

    @Override
    public Wall makeWall(){
        return new BombedWall();
    }
    @Override
    public Room makeRoom(int n){
        return new RoomWithABomb(n);
    }
}

class EnchantedMazeGame extends MazeGame {
    public EnchantedMazeGame(){}
    @Override
    public Room makeRoom(int n){
        return new EnchantedRoom(n, castSpell());
    }

    private int castSpell(){
        return 1;
    }

    @Override
    public Door makeDoor(Room r1, Room r2){
        return new DoorNeedingSpell(r1, r2);
    }
}

class Solution {
    public static void main(String[] args){
        MazeGame enchantedMazeGame = new EnchantedMazeGame();
        Maze maze = enchantedMazeGame.createMaze();
        maze.printLayout();

    }
}