module Api
  module V1
    class Beverage < ActiveRecord::Base
      extend Enumerize
      enumerize :kind , in: [:coffee, :tea]
      validates :kind, presence: true
    end
  end
end
