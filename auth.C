#include "auth.h"
#include <Wt/WText>

AuthForm::AuthForm(WContainerWidget *parent)
	 :WContainerWidget(parent)
{
   session_.login().changed().connect(this, &AuthForm::authEvent);
   authEvent();
   authwidget = new Auth::AuthWidget(session::auth(), session_.users(), session_.login());

   authwidget->model()->addPasswordAuth(session_.passwordAuth());
   authwidget->setRegistrationEnabled(true);

   authwidget->processEnvironment();

   this->addWidget(authwidget);
}

void AuthForm::authEvent()
{

   if(session_.login().loggedIn())
   {
      if(checkAdmin()){
         new WText("You are admin", this);
      }
      else{ 
         new WText("you are NOT ADMIN, visitor", this);
      }
   }
   else
   {
      std::cout<<"you are not logged in bai";
   }
}

bool AuthForm::checkAdmin()
{
   if(session_.userFunc() && session_.userFunc()->role == user::Admin)
      return true;
   else
      return false;
}
