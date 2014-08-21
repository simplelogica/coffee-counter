Rails.application.routes.draw do
  root "application#index"
  
  namespace :api, defaults: {format: :json} do
    # Version num1
    namespace :v1 do
      resources :coffees
    end
  end
end
