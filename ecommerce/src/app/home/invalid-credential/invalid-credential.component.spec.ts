import { ComponentFixture, TestBed } from '@angular/core/testing';

import { InvalidCredentialComponent } from './invalid-credential.component';

describe('InvalidCredentialComponent', () => {
  let component: InvalidCredentialComponent;
  let fixture: ComponentFixture<InvalidCredentialComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ InvalidCredentialComponent ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(InvalidCredentialComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
