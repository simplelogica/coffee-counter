class CreateCoffees < ActiveRecord::Migration
  def change
    create_table :coffees do |t|
      t.datetime :date

      t.timestamps
    end
  end
end
