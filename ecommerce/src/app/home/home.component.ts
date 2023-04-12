import { Component } from '@angular/core';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent {
    ecommerceWelcomeMessage : string = "Welcome to ecommerce site!";
    testPara: string = "Testing paragraph";
}
