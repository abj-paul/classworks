import { Injectable } from '@angular/core';
import {User} from "../models/User";

@Injectable({
  providedIn: 'root'
})
export class UserService {

  user_db : User[] = [
    {username:"Seller", password:"stu458", age:21, email:"admin@gmail.com", role:"SELLER"},
    {username:"Buyer", password:"stu458", age:21, email:"admin@gmail.com", role:"BUYER"}
  ];

  constructor() { }

  addUser(username:string, password: string, age: number, email: string, role:string): void{
    const user : User = {
      "username": username,
      "age": age,
      "email": email,
      "password": password,
      "role": role
    }

    this.user_db.push(user);
  }

  getRegisteredUsers(): User[]{
    return this.user_db;
  }

  authenticate(username:string, password:string): boolean{
    for(let i=0; i<this.user_db.length; i++){
      if(this.user_db[i].username==username && this.user_db[i].password==password){
        console.log("Valid Credentials for user "+username);
        return true;
      }
    }
    console.log("Invalid Credentials.");
    return false;
  } 
}
