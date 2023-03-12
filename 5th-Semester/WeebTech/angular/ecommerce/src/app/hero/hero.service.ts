import { Injectable } from '@angular/core';
import { Hero } from "./hero";

@Injectable({
  providedIn: 'root'
})
export class HeroService{

  constructor() { }

  heroes: Hero[] = [
    {id:1, name:"Tigreal", role: "tank", level: 20},
    {id:2, name:"Layla", role: "MM", level: 25},
    {id:3, name:"Harith", role: "Mage", level: 10},
  ];

  getHeroes(): Hero[] {
    return this.heroes;
  }
}
