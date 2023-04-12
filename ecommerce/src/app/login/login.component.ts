import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { UserService } from '../services/user.service';
import { AccessControlService } from '../services/access-control.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent {
  username: string = "";
  password: string = "";

  constructor(private userService: UserService, private router: Router, private accessControlService: AccessControlService){}

  authenticate(){
    const success = this.userService.authenticate(this.username, this.password);
    if(!success){
      this.router.navigate(['invalid-credentials']);
    }else {
      this.accessControlService.setLoggedInUser(this.username);
      this.router.navigate(['profile']);
    }
  }
}
