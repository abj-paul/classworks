import { Injectable } from '@angular/core';
import { Product } from '../models/Product';
import { compileNgModule } from '@angular/compiler';

@Injectable({
  providedIn: 'root'
})
export class ProductService {

  product_db : Product[] = [
    {name:"Shampoo", price:100, stock:10, owner: "Admin"},
    {name:"Oil", price:1120, stock:15, owner: "Admin"},
    {name:"Rice", price:87, stock:43, owner: "Admin"},
    {name:"Flour", price:92, stock:87, owner: "Admin"},
    {name:"Muri", price:34, stock:12, owner: "Admin"},
  ]

  constructor() { }

  addProduct(productName:string, price:number, stock:number, owner:string):void{
    this.product_db.push({
      name:productName, price:price, stock:stock, owner:owner
    });
  }

  decrementProductStock(productName:string, amount:number):void{
    for(let i=0; i<this.product_db.length; i++){
      if(this.product_db[i].name==productName) {
        this.product_db[i].stock -= amount;
        break;
      }
    }
  }

  getProductList(): Product[]{
    return this.product_db;
  }

  removeProductList(productName:string): void {
    for(let i=0; i<this.product_db.length; i++){
      if(this.product_db[i].name==productName) 
      {
        delete this.product_db[i]; 
        break;
      }
    }
  }

  incrementStock(index: number): void {
    this.product_db[index].stock++;
  }
  decrementStock(index: number): void {
    this.product_db[index].stock--;
  }

  update(originalProductName:string, productName:string, price:number, stock:number, owner:string){
    for(let i=0; i<this.product_db.length; i++){
      if(this.product_db[i].name==originalProductName){
        this.product_db[i].name = productName;
        this.product_db[i].price = price;
        this.product_db[i].stock = stock;
        this.product_db[i].owner = owner;
        return;
      }
    }
    console.log("Invalid credentials! Failed to update data...");
  }

  buy(product: Product, amount:number){
    for(let i=0; i<this.product_db.length; i++){
      if(this.product_db[i]==product){
        this.product_db[i].stock-=amount;
        break;
      }
    }
  }

}
