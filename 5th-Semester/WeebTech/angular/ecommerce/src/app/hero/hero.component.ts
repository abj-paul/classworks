import { Component, inject, OnInit } from '@angular/core';
import { HeroService } from './hero.service';
import { Hero } from './hero';
import { Inject } from '@angular/core';

@Component({
  selector: 'app-hero',
  templateUrl: './hero.component.html',
  styleUrls: ['./hero.component.css']
})
export class HeroComponent implements OnInit{
  constructor(private heroService: HeroService){}
  heroList: Hero[] = [];

  ngOnInit(): void {
    this.heroList = this.heroService.getHeroes();
    console.log(this.heroList);
  }

}
