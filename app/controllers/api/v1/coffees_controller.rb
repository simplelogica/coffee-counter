module Api
  module V1
    class CoffeesController < ApplicationController
      # GET /coffees
      # GET /coffees.json
      def index
        @coffees = Coffee.all

        render json: @coffees
      end

      # GET /coffees/1
      # GET /coffees/1.json
      def show
        @coffee = Coffee.find(params[:id])

        render json: @coffee
      end

      # POST /coffees
      # POST /coffees.json
      def create
        @coffee = Coffee.new(params[:coffee])

        if @coffee.save
          render json: @coffee, status: :created, location: @coffee
        else
          render json: @coffee.errors, status: :unprocessable_entity
        end
      end

      # PATCH/PUT /coffees/1
      # PATCH/PUT /coffees/1.json
      def update
        @coffee = Coffee.find(params[:id])

        if @coffee.update(params[:coffee])
          head :no_content
        else
          render json: @coffee.errors, status: :unprocessable_entity
        end
      end

      # DELETE /coffees/1
      # DELETE /coffees/1.json
      def destroy
        @coffee = Coffee.find(params[:id])
        @coffee.destroy

        head :no_content
      end
    end
  end
end
