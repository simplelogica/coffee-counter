Rails.application.routes.draw do
  root "application#index"

  namespace :api, defaults: {format: :json} do
    # Version num1
    namespace :v1 do
      get 'beverages/:kind', to: 'beverages#index'
      post 'beverages/:kind', to: 'beverages#create'
      delete 'beverages/:kind', to: 'beverages#destroy'
    end
  end
end
