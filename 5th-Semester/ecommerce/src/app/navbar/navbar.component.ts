import { Component } from '@angular/core';
import { AccessControlService } from '../services/access-control.service';

@Component({
  selector: 'app-navbar',
  templateUrl: './navbar.component.html',
  styleUrls: ['./navbar.component.css']
})
export class NavbarComponent {
  constructor(private accessControlService: AccessControlService){}

  whichRole():string{
     return this.accessControlService.getLoggedInUser().role;
  }
}
