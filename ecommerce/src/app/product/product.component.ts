import { Component, OnInit } from '@angular/core';
import { Product } from '../models/Product';
import { ProductService } from '../services/product.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-product',
  templateUrl: './product.component.html',
  styleUrls: ['./product.component.css']
})
export class ProductComponent implements OnInit{
  productList: Product[] = []

  productName: string = "";
  price: number = 0;
  stock: number = 0;
  username: string = "";

  originalProduct: Product = new Product();

  constructor(private productService: ProductService, private router: Router){}

  ngOnInit(): void {
    this.productList = this.productService.getProductList();
  }

  forwardToAddProductPage():void{
    this.router.navigate(["add-product"]);
  }
  incrementStock(index:number):void{
    this.productService.incrementStock(index);
  }
  decrementStock(index:number): void {
    this.productService.decrementStock(index);
  }
  informUpdate(product: Product):void{
    this.originalProduct = product;
    this.productName = product.name;
    this.stock = product.stock;
    this.price = product.price;
    this.username = product.owner;
  }
  updateProductInfo():void{
    this.productService.update(this.originalProduct.name, this.productName, this.price, this.stock, this.username);
    this.originalProduct = new Product();
    this.router.navigate(["product"]);
  }

  isUpdating(product: Product):boolean{
    if(this.originalProduct==product) return true;
    return false;
  }
}
