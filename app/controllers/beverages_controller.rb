
class BeveragesController < ApplicationController
  # GET /beverages
  # GET /beverages.json
  def index
    @totals =  {}
    Beverage.kind.values.each do |kind|
      @totals[kind] = Beverage.where(kind: kind).count
    end
    render :index
  end

end
