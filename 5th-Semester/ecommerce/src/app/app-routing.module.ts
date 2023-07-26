import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { InvalidCredentialComponent } from './home/invalid-credential/invalid-credential.component';
import { LoginComponent } from './login/login.component';
import { ProfileComponent } from './profile/profile.component';
import { RegistrationComponent } from './registration/registration.component';
import { ProductComponent } from './product/product.component';
import { AddProductComponent } from './product/add-product/add-product.component';
import { BuyComponent } from './product/buy/buy.component';

const routes: Routes = [
  {path: "", component: HomeComponent},
  {path:"home", component: HomeComponent},
  {path:"login", component: LoginComponent},
  {path: "registration", component: RegistrationComponent},
  {path: "invalid-credentials", component: InvalidCredentialComponent},
  {path: "profile", component: ProfileComponent},
  {path: "product", component: ProductComponent},
  {path: "add-product", component: AddProductComponent},
  {path: "buy", component: BuyComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
