class CreateBeverages < ActiveRecord::Migration
  def change
    create_table :beverages do |t|
      t.string :kind

      t.timestamps
    end
    add_index :beverages, :kind
  end
end
