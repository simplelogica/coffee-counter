require 'test_helper'

class CoffeesControllerTest < ActionController::TestCase
  setup do
    @coffee = coffees(:one)
  end

  test "should get index" do
    get :index
    assert_response :success
    assert_not_nil assigns(:coffees)
  end

  test "should create coffee" do
    assert_difference('Coffee.count') do
      post :create, coffee: { date: @coffee.date }
    end

    assert_response 201
  end

  test "should show coffee" do
    get :show, id: @coffee
    assert_response :success
  end

  test "should update coffee" do
    put :update, id: @coffee, coffee: { date: @coffee.date }
    assert_response 204
  end

  test "should destroy coffee" do
    assert_difference('Coffee.count', -1) do
      delete :destroy, id: @coffee
    end

    assert_response 204
  end
end
