module Api
  module V1
    class BeveragesController < ApplicationController
      # GET /beverages
      # GET /beverages.json
      def index
        @beverages = Beverage.all

        render json: @beverages
      end

      # GET /beverages/1
      # GET /beverages/1.json
      def show
        @beverage = Beverage.find(params[:id])

        render json: @beverage
      end

      # POST /beverages
      # POST /beverages.json
      def create
        @beverage = Beverage.new(params[:beverage])

        if @beverage.save
          render json: @beverage, status: :created, location: @beverage
        else
          render json: @beverage.errors, status: :unprocessable_entity
        end
      end

      # PATCH/PUT /beverages/1
      # PATCH/PUT /beverages/1.json
      def update
        @beverage = Beverage.find(params[:id])

        if @beverage.update(params[:beverage])
          head :no_content
        else
          render json: @beverage.errors, status: :unprocessable_entity
        end
      end

      # DELETE /beverages/1
      # DELETE /beverages/1.json
      def destroy
        @beverage = Beverage.find(params[:id])
        @beverage.destroy

        head :no_content
      end
    end
  end
end
