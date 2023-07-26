import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { Product } from 'src/app/models/Product';
import { ProductService } from 'src/app/services/product.service';

@Component({
  selector: 'app-buy',
  templateUrl: './buy.component.html',
  styleUrls: ['./buy.component.css']
})
export class BuyComponent implements OnInit{
  productList: Product[] = [];
  purchaseAmount: number = 0;

  buyOngoing: boolean = false;
  selectedProduct: Product = new Product();

  constructor(private productService: ProductService, private router: Router){}

  ngOnInit(): void {
    this.productList = this.productService.getProductList();
  }

  toggleBuy():void{
    if(this.buyOngoing) this.buyOngoing = false;
    this.buyOngoing = true;
  }

  buy(product: Product):void {
    if(this.buyOngoing){
      this.productService.buy(product, this.purchaseAmount);
      this.selectedProduct = new Product();
      this.toggleBuy();
    } else {
      this.selectedProduct = product;
      this.toggleBuy();
    }
  }

  shouldIShowTextbox(product: Product){
    if(product==this.selectedProduct) return true;
    return false;
  }
}
