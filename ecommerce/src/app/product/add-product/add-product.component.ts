import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { ProductService } from 'src/app/services/product.service';

@Component({
  selector: 'app-add-product',
  templateUrl: './add-product.component.html',
  styleUrls: ['./add-product.component.css']
})
export class AddProductComponent {
  name: string = "";
  price: number = 0;
  stock: number = 0;
  ownerName: string = "Default name";

  constructor(private productService: ProductService, private router: Router){}

  addProduct():void{
    this.productService.addProduct(this.name, this.price, this.stock, this.ownerName);
    this.router.navigate(["product"]);
  }
}
