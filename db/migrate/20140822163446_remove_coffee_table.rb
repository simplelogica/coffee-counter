class RemoveCoffeeTable < ActiveRecord::Migration
  def change
    drop_table :coffees
  end
end
