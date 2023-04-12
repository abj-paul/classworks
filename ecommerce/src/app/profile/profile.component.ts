import { Component } from '@angular/core';
import { AccessControlService } from '../services/access-control.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-profile',
  templateUrl: './profile.component.html',
  styleUrls: ['./profile.component.css']
})
export class ProfileComponent {
  constructor(private accessControlService: AccessControlService, private router: Router){}
  logout(){
    this.accessControlService.logout();
    this.router.navigate(["login"]);
  }
}
