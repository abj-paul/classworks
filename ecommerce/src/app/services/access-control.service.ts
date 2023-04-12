import { Injectable } from '@angular/core';
import { User } from '../models/User';
import { UserService } from './user.service';

@Injectable({
  providedIn: 'root'
})
export class AccessControlService {
  loggedInUser: User = new User();
  constructor(private userService: UserService) { }

  setLoggedInUser(username:string){
    const userList = this.userService.getRegisteredUsers();
    for(let i=0; i<userList.length; i++){
      if(userList[i].username == username){
        this.loggedInUser = userList[i];
        break;
      }
    }
  }
  getLoggedInUser():User{
    return this.loggedInUser;
  }

  logout():void{
    this.loggedInUser = new User();
  }
}
