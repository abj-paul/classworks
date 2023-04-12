import { Component } from '@angular/core';
import { UserService } from '../services/user.service';
import {User} from "../models/User";
import { Router } from '@angular/router';

@Component({
  selector: 'app-registration',
  templateUrl: './registration.component.html',
  styleUrls: ['./registration.component.css']
})
export class RegistrationComponent {
  constructor(private userService: UserService, private router: Router){}

  username: string = "";
  password: string = "";
  age: number = 0;
  email: string = "";
  role: string = "";

  registerNewUser(){
    this.userService.addUser(this.username, this.password, this.age, this.email, this.role);
    this.router.navigate(['profile']);
  }

  test(): void{
    const users = this.userService.getRegisteredUsers();
    for(let i=0; i<users.length; i++){
      console.log(users[i].username);
    }
  }
}
