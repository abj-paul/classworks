import { Component, OnInit } from '@angular/core';
import { AccessControlService } from '../services/access-control.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-profile',
  templateUrl: './profile.component.html',
  styleUrls: ['./profile.component.css']
})
export class ProfileComponent implements OnInit{

  username:string = "";
  age:number = 0;
  email: string = "";
  role: string = "";

  ngOnInit(): void {
    const user = this.accessControlService.getLoggedInUser();
    this.username = user.username;
    this.age = user.age;
    this.email = user.email;
    this.role = user.role;
  }
  constructor(private accessControlService: AccessControlService, private router: Router){}

  logout(){
    this.accessControlService.logout();
    this.router.navigate(["login"]);
  }
}
