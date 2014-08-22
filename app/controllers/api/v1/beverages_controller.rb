module Api
  module V1
    class BeveragesController < ApplicationController
      # GET /beverages
      # GET /beverages.json
      def index
        @beverages = Api::V1::Beverage.all
        @beverages = @beverages.where(kind: params[:kind]) if params[:kind]

        render json: @beverages
      end

      # POST /beverages
      # POST /beverages.json
      def create
        @beverage = Api::V1::Beverage.new(kind: params[:kind])

        if @beverage.save
          render json: @beverage, status: :created
        else
          render json: @beverage.errors, status: :unprocessable_entity
        end
      end

      # DELETE /beverages/1
      # DELETE /beverages/1.json
      def destroy
        @beverage = Api::V1::Beverage.where(kind: params[:kind]).last
        @beverage.destroy

        head :no_content
      end
    end
  end
end
